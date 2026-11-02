// gcc version 16.2.1 20260810 (GCC)
// $ gcc -fopenmp main.c

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 10
#define START 1000000000lu // sadly couldn't find a way to constexpr this
#define END START *LEN - 1

// converts a number into an array of its `LEN`-repr digits
void number_to_digits(ulong number, char *buf) {
  for (char i = LEN; i-- > 0;) {
    buf[i] = number % LEN;
    number /= LEN;
  }
}

void count_digits(ulong number, char *buf) {
  for (char i = LEN; i-- > 0;) {
    buf[number % LEN] += 1;
    number /= LEN;
  }
}

// compares bufs up to `LEN`
bool are_bufs_equal(char *const a, char *const b) {
  for (char i = LEN; i-- > 0;) {
    if (a[i] != b[i])
      return false;
  }
  return true;
}

bool is_autobiographical(ulong number) {
  char digits[LEN] = {0};
  number_to_digits(number, digits);

  char digit_counts[LEN] = {0};
  count_digits(number, digit_counts);

  return are_bufs_equal(digits, digit_counts);
}

int main(int argc, char *argv[]) {
#pragma omp parallel for
  for (ulong number = START; number <= END; number++)
    if (is_autobiographical(number))
      printf("%lu\n", number);

  return EXIT_SUCCESS;
}
