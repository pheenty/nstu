#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define eprintf(args...) fprintf(stderr, ##args)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMP(x, min, max) (MAX((MIN((x), (max))), (min)))

#define T int
#define T_MAX INT_MAX
#define T_MIN INT_MIN

#define LEN 10
#define INIT {-64, -100, 69, 100, 0, -74, 21, 24, -63, 64}
#define LOOPS 100

void bubble_sort(T *buf, size_t len) {
  for (size_t i = len; i-- > 0;)
    for (size_t j = len; j-- > 1;)
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

  T diff = max - min;
  for (size_t i, j, loop = LOOPS; loop-- > 0;) {
    i = rand() % len;
    while (true) {
      T ith = buf[i];
      j = CLAMP(diff == 0 ? i : (ith - min) * len / diff, 0, len - 1);

      if (i == j)
        break;

      buf[i] = buf[j];
      buf[j] = ith;
      i = j;
    }
  }
}

void print_buf(T *buf, size_t len) {
  for (size_t i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

int main(int argc, char *argv[]) {
  srand(0);
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
