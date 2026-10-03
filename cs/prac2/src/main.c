#include <stdio.h>
#include <stdlib.h>
#define eprintf(args...) fprintf(stderr, ##args)

// 1
// byval
int f_14(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    if (k > s)
      s = k;
  }

  return s;
}

// 2
// byval
// impure
void f_18(int *A, int v) {
  int j, a, s, n, k;

  for (j = 0, a = 10; a < v; a++) {
    for (n = a, s = 0; n != 0; n = n / 10) {
      k = n % 10;
      s = s * 10 + k;
    }

    if (a == s)
      A[j++] = a;
  }
}

// 3
// byval
// impure
void f_22(int *A, int v) {
  int i, a, n, s;

  for (i = 0, a = 2; a < v; a++) {
    for (s = 0, n = 2; n < a; n++)
      if (a % n == 0) {
        s = 1;
        break;
      }

    if (s == 0)
      A[i++] = a;
  }

  A[i] = 0;
}

// 4
// byval
// impure
void f_26(int *A, int n) {
  int j, i, s, m;

  for (j = 0, i = 0; i < n; i++) {
    for (s = 0, m = 2; m < A[i]; m++)
      if (A[i] % m == 0) {
        s = 1;
        break;
      }

    if (s == 0) {
      for (j = i; j < n - 1; j++)
        A[j] = A[j + 1];

      n--;
      i--;
    }
  }
}

// 5
// byref
int f_34(int *n_ptr) {
  int k, m, n = *n_ptr;

  for (k = 0, m = 1; m <= n; k++, m = m * 2)
    ;

  return k - 1;
}

// 6
// byref
int f_38(int *c, int *n_ptr) {
  int i, k, m, b, n = *n_ptr;

  for (i = k = m = 0; i < n - 1; i++)
    if (c[i] == c[i + 1])
      k++;
    else {
      if (k > m)
        m = k, b = i - k - 1;

      k = 0;
    }

  return b;
}

// 7
// byref
int f_41(int *A, int *n_ptr) {
  int k, s, i, n = *n_ptr;

  for (k = 0, s = 0, i = 0; i < n && k == 0; i++) {
    if (A[i] < 0)
      k = 1;

    s = s + A[i];
  }

  return s;
}

// 8
// byref (ptr)
int f_43(int *A, int *n_ptr) {
  int s, i, n = *n_ptr;

  for (s = 0, i = 0; i < n; i++) {
    if (i % 2 == 0)
      s = s + A[i];
    else
      s = s - A[i];
  }

  return s;
}

// 9
// byref (ptr)
// impure
void f_46(int *A, int *n_ptr) {
  int k, i, c, n = *n_ptr;

  while (n != 0) {
    for (k = 0, i = 1; i < n; i++)
      if (A[i] < A[k])
        k = i;

    c = A[k];
    A[k] = A[n - 1];
    A[n - 1] = c;
    n--;
  }
}

// 10
// byref (ptr)
// impure
void f_48(int *A, int *n_ptr) {
  int i, j, n = *n_ptr;

  for (i = 0; i < n - 1; i++)
    if (A[i] == A[i + 1]) {
      for (j = i; j < n - 2; j++)
        A[j] = A[j + 2];

      n = n - 2;
      i--;
    }
}

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", buf[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int len = 10;
  int *len_ptr = &len;

  int arg1 = 17;
  int *arg1_ptr = &arg1;
  int buf1[len];
  for (int i = len; i-- > 0;)
    buf1[i] = i;

  int arg2 = 42;
  int *arg2_ptr = &arg2;
  int buf2[len];
  for (int i = len; i-- > 0;)
    buf2[i] = i * 2 - 7;

  int arg3 = 1;
  int *arg3_ptr = &arg3;
  int buf3[len];
  for (int i = len; i-- > 0;)
    buf3[i] = i ^ 65;

  int result;

  result = f_14(arg1);
  printf("F14-1 = %d\n", result);
  result = f_14(arg2);
  printf("F14-2 = %d\n", result);
  result = f_14(arg3);
  printf("F14-3 = %d\n", result);

  f_18(buf1, len);
  printf("F18-1 = ");
  print_buf(buf1, len);
  f_18(buf2, len);
  printf("F18-2 = ");
  print_buf(buf2, len);
  f_18(buf3, len);
  printf("F18-3 = ");
  print_buf(buf3, len);

  f_22(buf1, len);
  printf("F22-1 = ");
  print_buf(buf1, len);
  f_22(buf2, len);
  printf("F22-2 = ");
  print_buf(buf2, len);
  f_22(buf3, len);
  printf("F22-3 = ");
  print_buf(buf3, len);

  f_26(buf1, len);
  printf("F26-1 = ");
  print_buf(buf1, len);
  f_26(buf2, len);
  printf("F26-2 = ");
  print_buf(buf2, len);
  f_26(buf3, len);
  printf("F26-3 = ");
  print_buf(buf3, len);

  result = f_34(arg1_ptr);
  printf("F34-1 = %d\n", result);
  result = f_34(arg2_ptr);
  printf("F34-2 = %d\n", result);
  result = f_34(arg3_ptr);
  printf("F34-3 = %d\n", result);

  result = f_38(buf1, len_ptr);
  printf("F38-1 = %d\n", result);
  result = f_38(buf2, len_ptr);
  printf("F38-2 = %d\n", result);
  result = f_38(buf3, len_ptr);
  printf("F38-3 = %d\n", result);

  result = f_41(buf1, &len);
  printf("F41-1 = %d\n", result);
  result = f_41(buf2, &len);
  printf("F41-2 = %d\n", result);
  result = f_41(buf3, &len);
  printf("F41-3 = %d\n", result);

  result = f_43(buf1, &len);
  printf("F43-1 = %d\n", result);
  result = f_43(buf2, &len);
  printf("F43-2 = %d\n", result);
  result = f_43(buf3, &len);
  printf("F43-3 = %d\n", result);

  f_46(buf1, &len);
  printf("F46-1 = ");
  print_buf(buf1, len);
  f_46(buf2, &len);
  printf("F46-1 = ");
  print_buf(buf2, len);
  f_46(buf3, &len);
  printf("F46-1 = ");
  print_buf(buf3, len);

  return EXIT_SUCCESS;
}
