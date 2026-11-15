#include <stdio.h>
#include <stdlib.h>
#define n 10

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

#define REWRITTEN

int main(int argc, char *argv[]) {
  int A[n] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  int B[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i, j, m;

#ifdef REWRITTEN
  i = j = 0;
  while (i < n) {
    m = 2;
    do {
      if (A[i] % m == 0) {
        m++;
        break;
      }
      m++;
    } while (m < A[i]);

    if (m == A[i])
      B[j++] = A[i];

    i++;
  }
#else
  for (j = 0, i = 0; i < n; i++) {
    for (m = 2; m < A[i]; m++) {
      if (A[i] % m == 0)
        break;
    }
    if (m == A[i])
      B[j++] = A[i];
  }
#endif

  B[j] = 0;
  print_buf(B, n);

  return EXIT_SUCCESS;
}
