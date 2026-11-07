#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define eprintf(args...) fprintf(stderr, ##args)

#define T int
#define T_MAX INT_MAX
#define T_MIN INT_MIN

#define SEED 65

#define LEN 10
#define INIT {0, -2, -6, -1, 0, 4, 2, 1, -4, 4}

#define SIZE_COUNT 3
#define SIZES {1000, 5000, 10000}

static size_t OPS = 0;

void bubble_sort(T *buf, size_t len) {
  for (size_t i = len; i-- > 1;)
    for (size_t j = 0; j++ < i; OPS++)
      if (buf[j - 1] > buf[j]) {
        T tmp = buf[j - 1];
        buf[j - 1] = buf[j];
        buf[j] = tmp;
      }
}

void swap_sort(T *buf, size_t len) {
  T min = T_MAX, max = T_MIN;
  for (size_t i = len; i-- > 0; OPS++) {
    min = MIN(min, buf[i]);
    max = MAX(max, buf[i]);
  }

  for (size_t idx, jdx, i = len / 2; idx = rand() % len, i-- > 0;)
    for (size_t j = len; j-- > 0; OPS++) {
      T ith = buf[idx];
      jdx = (ith - min) * (len - 1) / (max - min);

      buf[idx] = buf[jdx];
      buf[jdx] = ith;
    }

  bubble_sort(buf, len);
}

void print_buf(T *buf, size_t len) {
  for (size_t i = 0; i < len; i++)
    printf("%d ", buf[i]);
}

int main(int argc, char *argv[]) {
  srand(SEED);

  // check that it even works
  T buf[LEN] = INIT;
  swap_sort(buf, LEN);
  print_buf(buf, LEN);
  printf("\n");

  // measure complexity
  size_t sizes[SIZE_COUNT] = SIZES;

  size_t offset = sizes[SIZE_COUNT - 1]; // largest
  T *heapbuf = malloc(sizeof(T) * offset);
  if (heapbuf == NULL) {
    eprintf("alloc fault\n");
    return EXIT_FAILURE;
  }
  for (; offset-- > 0;)
    heapbuf[offset] = rand();

  for (size_t i = 0; i < SIZE_COUNT; i++) {
    OPS = 0;
    size_t size = sizes[i];
    swap_sort(heapbuf, size);
    printf("ops for %zu-sized buf: %zu\n", size, OPS);
  }

  free(heapbuf);

  return EXIT_SUCCESS;
}
