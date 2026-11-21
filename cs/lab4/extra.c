#include <stdio.h>
#include <stdlib.h>

#define eprintf(args...) fprintf(stderr, ##args)

// merge sort?
void sort11(int A[], int n) {
  int i, i1, i2, s, k;

  for (s = 1; 1; s *= 2) {
    int nn = n / s;
    if (n % s != 0)
      nn++;

    int n1 = nn / 2 * s;
    int n2 = n - n1;

    if (n1 <= 0 || n2 <= 0)
      return;

    int *B1 = malloc(n1 * sizeof(int)), *B2 = malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
      B1[i] = A[i];

    for (i = 0; i < n2; i++)
      B2[i] = A[i + n1];

    i1 = i2 = 0;
    for (i = 0, k = 0; i < n; i++) {
      if (i1 == s && i2 == s)
        k += s, i1 = 0, i2 = 0;
      if (i1 == s || k + i1 == n1)
        A[i] = B2[k + i2++];
      else if (i2 == s || k + i2 == n2)
        A[i] = B1[k + i1++];
      else if (B1[k + i1] < B2[k + i2])
        A[i] = B1[k + i1++];
      else
        A[i] = B2[k + i2++];
    }

    free(B1);
    free(B2);
  }
}

// recursively puts larger numbers in the second half of the buffer
void sort14(int in[], int a, int b) {
  int i, j, mode;
  if (a >= b)
    return;

  for (i = a, j = b, mode = 1; i < j; mode > 0 ? j-- : i++)
    if (in[i] > in[j]) {
      int c = in[i];
      in[i] = in[j];
      in[j] = c;
      mode = -mode;
    }

  sort14(in, a, i - 1);
  sort14(in, i + 1, b);
}

void write_random_bytes(int *buf, size_t len) {
  for (size_t i = len; i-- > 0;)
    buf[i] = rand() % 1000;
}

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

void prepare(int *buf, int len) {
  write_random_bytes(buf, len);
  printf("Unsorted: ");
  print_buf(buf, len);
  printf("\n");
}

int main(int argc, char *argv[]) {
  srand(65);

#define LEN 10
  int *buf = malloc(LEN * sizeof(int));
  if (buf == NULL) {
    eprintf("alloc fault");
    exit(EXIT_FAILURE);
  }

  prepare(buf, LEN);
  printf("Sort 11: ");
  sort11(buf, LEN);
  print_buf(buf, LEN);
  printf("\n");

  prepare(buf, LEN);
  printf("Sort 14: ");
  sort14(buf, 0, LEN);
  print_buf(buf, LEN);
  printf("\n");

  return EXIT_SUCCESS;
}
