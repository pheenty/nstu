#include <stdio.h>
#include <stdlib.h>
#define n 10

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

int main(int argc, char *argv[]) {
  int A[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int B[n] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
  int i = 0, j = 0, m;

  while (i < n) {
    m = 2;
    if (m < A[i])
      continue;

    do {
      if (A[i] % m == 0)
        break;
      m++;
    } while (m < A[i]);

    if (m == A[i])
      B[j++] = A[i];

    i++;
  }

  B[j] = 0;

  print_buf(B, n);

  return EXIT_SUCCESS;
}
