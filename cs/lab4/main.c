#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define T int
#define T_MAX INT_MAX
#define T_MIN INT_MIN

#define SEED 65

#define LEN 10
#define INIT {0, -2, -6, -1, 0, 4, 2, 1, -4, 4}
#define LOOPS 5

void bubble_sort(T *buf, size_t len) {
  for (size_t i = len; i-- > 1;)
    for (size_t j = 0; j++ < i;)
      if (buf[j - 1] > buf[j]) {
        T tmp = buf[j - 1];
        buf[j - 1] = buf[j];
        buf[j] = tmp;
      }
}

void swap_sort(T *buf, size_t len) {
  T min = T_MAX, max = T_MIN;
  for (size_t i = len; i-- > 0;) {
    min = MIN(min, buf[i]);
    max = MAX(max, buf[i]);
  }

  for (size_t idx, jdx, i = LOOPS; idx = rand() % len, i-- > 0;)
    for (size_t j = len; j-- > 0;) {
      T ith = buf[idx];
      jdx = (ith - min) * (len - 1) / (max - min);

      buf[idx] = buf[jdx];
      buf[jdx] = ith;
    }
}

void print_buf(T *buf, size_t len) {
  for (size_t i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

int main(int argc, char *argv[]) {
  srand(SEED);
  T buf[LEN] = INIT;

  swap_sort(buf, LEN);
  printf("after swap sort: ");
  print_buf(buf, LEN);
  printf("\n");

  bubble_sort(buf, LEN);
  printf("after bubble sort: ");
  print_buf(buf, LEN);
  printf("\n");

  return EXIT_SUCCESS;
}
