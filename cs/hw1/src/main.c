#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 10

#define RETRY_GET_LEN
#define TEST_UB
// #define GLOBAL_BUF

#ifdef GLOBAL_BUF
int buf[MAX_LEN];
#endif

int get_len() {
  int len;
  printf("Enter array length (max %d): ", MAX_LEN);
  scanf("%d", &len);
  return (len >= 0 && len <= MAX_LEN) ? len :
#ifdef RETRY_GET_LEN
                                      get_len()
#else
                                      -1
#endif
      ;
}

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++)
    printf("%d  ", buf[i]);
}

void ub(int *buf, int len) { print_buf(buf + len, MAX_LEN - len); }

int main(int argc, char *argv[]) {
#ifndef GLOBAL_BUF
  int buf[MAX_LEN];
#endif

  int len = get_len();
  if (len < 0) {
    fprintf(stderr, "Invalid length, must be non-negative integer <= %d",
            MAX_LEN);
    return len;
  }

  for (int i = 0; i < len; i++) {
    printf("Enter number %d: ", i);
    scanf("%d", &buf[i]);
  }

#ifdef TEST_UB
  ub(buf, len);
#else
  print_buf(buf, len);
#endif

  return EXIT_SUCCESS;
}
