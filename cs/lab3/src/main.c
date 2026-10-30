#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define eprintf(args...) fprintf(stderr, ##args)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

// init: {NULL, 0, 0}
// the owner calls free(.ptr)
typedef struct {
  char *buf;
  size_t len;
  size_t cap;
} strbuf;

// false for alloc fault
bool strbuf_push(strbuf *strbuf, char const *str, size_t len) {
  size_t newsize = (strbuf->len + len);

  if (newsize > strbuf->cap) {
#define FACTOR 2
    size_t newcap = max(strbuf->cap * FACTOR, newsize);

    char *newptr = realloc(strbuf->buf, newcap);
    if (newptr == NULL)
      return false;

    strbuf->cap = newcap;
    strbuf->buf = newptr;
  }

  memcpy(strbuf->buf + strbuf->len, str, len);
  strbuf->len += len;

  return true;
}

// false for oob
bool strbuf_remove(strbuf *strbuf, size_t idx, size_t len) {
  size_t end = idx + len;
  if (end > strbuf->len)
    return false;

  memmove(strbuf->buf + idx, strbuf->buf + idx + len, strbuf->len - end);
  strbuf->len -= len;

  return true;
}

bool find_repeated_fragment(const strbuf *strbuf, size_t min_len,
                            size_t *out_fst, size_t *out_snd, size_t *out_len) {
  for (size_t fst = 0; fst + 2 * min_len <= strbuf->len; fst++)
    for (size_t snd = fst + min_len; snd + min_len <= strbuf->len; snd++) {
      size_t max_len =
          min(snd - fst, strbuf->len - snd); // so it doesn't overlap

      size_t len = 0;
      while (len < max_len) {
        char a = strbuf->buf[fst + len];
        char b = strbuf->buf[snd + len];
        if (a != b || a == ' ')
          break;
        len++;
      }

      if (len >= min_len) {
        *out_fst = fst;
        *out_snd = snd;
        *out_len = len;
        return true;
      }
    }

  return false;
}

#define LEN 6
#define INIT                                                                   \
  "saddsjofsajf jsdjfs dj fjfdsjifjodsjofsdj oifdujsaids jkfiosdjfd opl"       \
  "jfdsjisakjfiolfpo dsakjfiolsd jfkujsaidkdf jfdsjifjodsoil sdjdsdolik"

int main(int argc, char *argv[]) {
  int exitcode = EXIT_FAILURE;

  strbuf from = {NULL, 0, 0};
  strbuf to = {NULL, 0, 0};

  if (!strbuf_push(&from, INIT, strlen(INIT))) {
    eprintf("alloc fault\n");
    goto exit;
  }

  size_t first, second, len;
  while (find_repeated_fragment(&from, LEN, &first, &second, &len)) {
    if (!strbuf_push(&to, from.buf + first, len) ||
        !strbuf_push(&to, from.buf + second, len)) {
      eprintf("alloc fault\n");
      goto exit;
    }

    // remove second first so first stays valid second (pun not intended)
    if (!strbuf_remove(&from, second, len) ||
        !strbuf_remove(&from, first, len)) {
      eprintf("out of bounds\n");
      goto exit;
    }
  }

  if (!strbuf_push(&to, from.buf, from.len)) {
    eprintf("alloc fault\n");
    goto exit;
  }

  printf("Result: ");
  fwrite(to.buf, sizeof(char), to.len, stdout);
  printf("\n");

  exitcode = EXIT_SUCCESS;

exit:
  free(from.buf);
  free(to.buf);
  return exitcode;
}
