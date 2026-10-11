#include <stdio.h>
#include <stdlib.h>

// finds the largest digit in the number's decimal repr
int F9(int number) {
  int x, current_last_digit, max_digit;

  for (x = number, max_digit = 0; x != 0; x = x / 10) {
    current_last_digit = x % 10;
    if (current_last_digit > max_digit)
      max_digit = current_last_digit;
  }

  return max_digit;
}

// fills the buf with prime numbers up to `max`, terminating with 0
void F14(int max, int buf[], int len) {
  int idx, useless, i, j;

  for (idx = 0, i = 2; i < max && idx < len - 1; i++) {
    for (j = 0; j < idx; j++) {
      if (i % buf[j] == 0)
        break;
    }

    if (j == idx)
      buf[idx++] = i;
  }

  buf[idx] = 0;
}

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", buf[i]);
  }
}

int main(int argc, char *argv[]) {
  int f9 = F9(1357642); // expected: 7
  printf("f9 = %d\n", f9);

#define len 7
  int buf[len] = {1, 3, 5, 12, 4, 13, 2};
  F14(10, buf, len);
  printf("f14 = ");
  print_buf(buf, len); // expected: 2, 3, 5, 7, 0, ...

  return EXIT_SUCCESS;
}
