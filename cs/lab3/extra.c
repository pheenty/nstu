#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// reverses the string
void F1(char c[]) {
  int i, j;
  for (i = 0; c[i] != '\0'; i++) // poor man's strlen
    ;
  for (j = 0, i--; i > j; i--, j++) { // sliding ptrs
    // swap the chars
    char s;
    s = c[i];
    c[i] = c[j];
    c[j] = s;
  }
}

// finds substring
int F9(char c1[], char c2[]) {
  int i, j;
  for (i = 0; c1[i] != '\0'; i++) { // for every idx in c1
    for (j = 0; c2[j] != '\0'; j++) // as long as they match
      if (c1[i + j] != c2[j])
        break;
    if (c2[j] == '\0')
      return i; // and if c2 is done return c1 idx
  }
  return -1; // else -1
}

int main(int argc, char *argv[]) {
  char *fst = "This is some example string.";
// f1 requires a changeable buffer
#define SND "example"
  char *snd = malloc(sizeof SND);
  if (snd == NULL) {
    fprintf(stderr, "alloc fault\n");
    return EXIT_FAILURE;
  }
  memcpy(snd, SND, sizeof SND);

  size_t idx = F9(fst, snd);
  printf("%lu\n", idx);

  F1(snd);
  fwrite(snd, sizeof(char), sizeof SND, stdout);
  printf("\n");

  free(snd);

  return EXIT_SUCCESS;
}
