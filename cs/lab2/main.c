// gcc version 16.2.1 20260810 (GCC)
// $ gcc -lm main.c

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef double f64;

#define START 0.1
#define STEP 0.1
#define END 0.9
#define MAX_ERROR 0.00001

// used for checking whether series converges
#define N 10
#define X 0.5

f64 next_member(f64 x, f64 prev, u8 n) {
  return prev * (-x) * (2 * n - 1) / (2 * n);
}

bool is_series_converging() {
  f64 nth = 1;
  for (u8 n = 1; n <= N; n++)
    nth = next_member(X, nth, n);

  return fabs(nth) > fabs(next_member(X, nth, N + 1));
}

int main(int argc, char *argv[]) {
  assert(is_series_converging());

  for (f64 x = START; x <= END + STEP / 2; // accounting for fp errors
       x += STEP) {
    f64 actual = 1 / sqrt(1 + x);

    f64 approx = 0, nth = 1;
    u8 n = 0;
    do {
      approx += nth;
      nth = next_member(x, nth, ++n);
    } while (fabs(actual - approx) > MAX_ERROR);

    printf("x = %.1f | actual = %f | approx = %f | n = %d\n", x, actual, approx,
           n);
  }

  return EXIT_SUCCESS;
}
