// https://cprog.netlify.app/book/2/2.5#%D0%B2%D0%BE%D0%BF%D1%80%D0%BE%D1%81%D1%8B-%D0%B1%D0%B5%D0%B7-%D0%BE%D1%82%D0%B2%D0%B5%D1%82%D0%BE%D0%B2

#include <stdio.h>
#include <stdlib.h>
#define eprintf(args...) fprintf(stderr, ##args)

// sum of digits (hereinafter all is decimal repr)
int f_13(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    s = s + k;
  }

  return s;
}

// largest digit
int f_14(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    if (k > s)
      s = k;
  }

  return s;
}

// reverse digits
int f_15(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    s = s * 10 + k;
  }

  return s;
}

// write a digits into A, msd, -1-terminated
void f_16(int *A, int a) {
  int i, n;

  for (i = 0, n = a; n != 0; i++, n = n / 10)
    ;

  for (A[i--] = -1, n = a; n != 0; i--, n = n / 10)
    A[i] = n % 10;
}

// A = 10..30000 | filter sumofdigits == cubed
// -1 for error
int f_17(int *A, int len) {
  if (len < 30000) {
    return -1;
  }

  int a, j, k, s, n;

  for (j = 0, a = 10; a < 30000; a++) { // ??
    for (n = a, s = 0; n != 0; n = n / 10) {
      k = n % 10;
      s = s + k;
    }

    if (a == s * s * s)
      A[j++] = a;
  }

  return 0;
}

// A = 10..v | filter ispalindrome
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

// A = A | filter < 0
void f_19(int *A, int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    if (A[i] < 0) {
      for (j = i; j < n - 1; j++)
        A[j] = A[j + 1];

      n--;
      i--;
    }
  }
}

// removes first entry of max el
void f_20(int *A, int n) {
  int i, k, j;

  for (i = 1, k = 0; i < n; i++)
    if (A[i] > A[k])
      k = i;

  for (j = k; j < n - 1; j++)
    A[j] = A[j + 1];

  n--; // ??
}

// A = primes < v, 0-terminated
void f_21(int *A, int v) {
  int i, a, n;

  for (i = 0, a = 2; a < v; a++) {
    for (n = 2; n < a; n++) {
      if (a % n == 0)
        break;
    }

    if (n == a)
      A[i++] = a;
  }

  A[i] = 0;
}

// same
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

// B = A | filter isprime
void f_23(int const *A, int *B, int n) {
  int j, i, m;

  for (j = 0, i = 0; i < n; i++) {
    for (m = 2; m < A[i]; m++) {
      if (A[i] % m == 0)
        break;
    }

    if (m == A[i])
      B[j++] = A[i];
  }

  B[j] = 0;
}

// same
void f_24(int const *A, int *B, int n) {
  int j, i, s, m;

  for (j = 0, i = 0; i < n; i++) {
    for (s = 0, m = 2; m < A[i]; m++)
      if (A[i] % m == 0) {
        s = 1;
        break;
      }

    if (s == 0)
      B[j++] = A[i];
  }

  B[j] = 0;
}

// A = A | filter isntprime
void f_25(int *A, int n) {
  int i, m, j;

  for (i = 0; i < n; i++) {
    for (m = 2; m < A[i]; m++) {
      if (A[i] % m == 0)
        break;
    }

    if (m == A[i]) {
      for (j = i; j < n - 1; j++)
        A[j] = A[j + 1];

      n--;
      i--;
    }
  }
}

// same
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

// store n prime factors in A, 0-terminated
void f_27(int *A, int n, int val) {
  int i, m;

  for (i = 0; i < n - 1 && val != 1; i++) {
    for (m = 2; val % m != 0; m++)
      ;

    val /= m;
    A[i] = m;
  }

  A[i] = 0;
}

// gcd
int f_28(int *A, int n) {
  int v, i, s;

  v = A[0] + 1;

  do {
    v--;

    for (i = 0, s = 0; i < n; i++)
      if (A[i] % v != 0) {
        s = 1;
        break;
      }
  } while (s == 1);

  return v;
}

// gcd < v
int f_29(int *A, int n, int v) {
  int i;

  for (i = 0; i < n; i++)
    if (A[i] % v != 0) {
      v--;
      i = -1;
    }

  return v;
}

// A = primes < v, at most m, 0-terminated
// -1 for error
int f_30(int *A, int len, int v, int m) {
  if (len < m)
    return -1;

  int i, a, s, j;

  for (i = 0, a = 2; a < v && i < m - 1; a++) {
    for (s = 0, j = 0; j < i; j++)
      if (a % A[j] == 0) {
        s = 1;
        break;
      }

    if (s == 0)
      A[i++] = a;
  }

  A[i] = 0;

  return 0;
}

// fst found idx of a duplicate
// -1 for err
int f_31(int const *c, int n) {
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (c[i] == c[j])
        return i;

  return -1;
}

// idx of fst entry of most common el
// -1 for err
int f_32(int const *c, int n) {
  int s, i, k, j, b = -1;

  for (s = 0, i = 0; i < n; i++) {
    for (k = 0, j = 0; j < n; j++)
      if (c[i] == c[j])
        k++;

    if (k > s)
      s = k, b = i;
  }

  return b;
}

// idx of longest run of equal els
// -1 for err
int f_33(int const *A, int n) {
  int s, i, k, b = -1;

  for (s = 0, i = 0; i < n - 1; i++)
    if (A[i] == A[i + 1]) {
      for (k = 2; i + k < n && A[i] == A[i + k]; k++)
        ;

      if (k > s)
        s = k, b = i;
    }

  return b;
}

// binary log?
int f_34(int n) {
  int k, m;

  for (k = 0, m = 1; m <= n; k++, m = m * 2)
    ;

  return k - 1;
}

// reverse
void f_35(int *c, int n) {
  int k, i, j;

  for (i = 0, j = n - 1; i < j; i++, j--) {
    k = c[i];
    c[i] = c[j];
    c[j] = k;
  }
}

// median
// -1 for err
int f_36(int const *c, int n) {
  int i, j, k1, k2;

  for (i = 0; i < n; i++) {
    for (j = k1 = k2 = 0; j < n; j++)
      if (c[i] != c[j]) {
        if (c[i] < c[j])
          k1++;
        else
          k2++;
      }

    if (k1 == k2)
      return i;
  }

  return -1;
}

// idx of fst entry of most common el
int f_37(int const *c, int n) {
  int s, i, j, m, b;

  for (s = 0, i = 0; i < n - 1; i++) {
    for (j = i + 1, m = 0; j < n; j++)
      if (c[i] == c[j])
        m++;

    if (m > s)
      s = m, b = i;
  }

  return b;
}

// longest equal run len
int f_38(int const *c, int n) {
  int i, k, m, b = 0;

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

// A | filter >= 0 | takewhile != 0. sum
int f_39(int const *A, int n) {
  int s, i;

  for (s = 0, i = 0; i < n; i++) {
    if (A[i] < 0)
      continue;

    if (A[i] == 0)
      break;

    s = s + A[i];
  }

  return s;
}

// A | takewhile > 0 | sum
int f_40(int const *A, int n) {
  int s, i;

  for (s = 0, i = 0; i < n && A[i] > 0; i++)
    s = s + A[i];

  return s;
}

// A | takewhile INCLUSIVE >= 0 | sum
int f_41(int const *A, int n) {
  int k, s, i;

  for (k = 0, s = 0, i = 0; i < n && k == 0; i++) {
    if (A[i] < 0)
      k = 1;

    s = s + A[i];
  }

  return s;
}

// heuristic partition point where two part sums are equal, assumes xs > 0
int f_42(int const *A, int n) {
  int s1, s2, i, j;

  for (s1 = 0, s2 = 0, i = 0, j = n - 1; i <= j;) {
    if (s1 < s2)
      s1 += A[i], i++;
    else
      s2 += A[j], j--;
  }

  return i;
}

// alternating sum
int f_43(int const *A, int n) {
  int s, i;

  for (s = 0, i = 0; i < n; i++) {
    if (i % 2 == 0)
      s = s + A[i];
    else
      s = s - A[i];
  }

  return s;
}

// B = A | sort
void f_44(int *A, int *B, int n) {
  int j, k, i;

  for (j = 0; n != 0; j++) {
    for (k = 0, i = 1; i < n; i++)
      if (A[i] < A[k])
        k = i;

    B[j] = A[k];

    for (; k < n - 1; k++)
      A[k] = A[k + 1];

    n--;
  }
}

// same
void f_45(int *A, int *B, int n) {
  int j, max, k, i;

  for (j = 0, max = A[0]; j < n; j++)
    if (A[j] > max)
      max = A[j];

  for (j = 0; j < n; j++) {
    for (k = 0, i = 1; i < n; i++)
      if (A[i] < A[k])
        k = i;

    B[j] = A[k];
    A[k] = max + 1;
  }
}

// descending selection sort
void f_46(int *A, int n) {
  int k, i, c;

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

// A = 10..v | map (x, digits x | filter != 0)
//      | filter (snd | all % fst == 0) | map fst
// -1 for error
int f_47(int *A, int len, int v) {
  if (v > len)
    return -1;

  int j, a, k, s, n;

  for (j = 0, a = 10; a < v; a++) {
    for (s = 0, n = a, s = 0; n != 0; n = n / 10) {
      k = n % 10;

      if (k != 0 && a % k != 0) {
        s = 1;
        break;
      }
    }

    if (s == 0)
      A[j++] = a;
  }

  A[j] = 0;

  return 0;
}

// rm adjacent equal pairs
void f_48(int *A, int n) {
  int i, j;

  for (i = 0; i < n - 1; i++)
    if (A[i] == A[i + 1]) {
      for (j = i; j < n - 2; j++)
        A[j] = A[j + 2];

      n = n - 2;
      i--;
    }
}

// idx of min non-negative in A[0..10]
// -1 for error
int f_49(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, k;

  for (i = 0, k = -1; i < 10; i++) {
    if (A[i] < 0)
      continue;

    if (k == -1)
      k = i;
    else if (A[i] < A[k])
      k = i;
  }

  return k;
}

// negative-to-positive transitions in A[0..10]
// -1 for error
int f_50(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s, k;

  for (i = 0, s = 0, k = 0; i < 10; i++)
    if (A[i] < 0)
      k = 1;
    else {
      if (k == 1)
        s++;

      k = 0;
    }

  return s;
}

// A | take 10 | max | max 0
// -1 for error
int f_51(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s;

  for (i = 0, s = 0; i < 10; i++)
    if (A[i] > s)
      s = A[i];

  return s;
}

// idx of max in A[0..10]
// -1 for error
int f_52(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, k;

  for (i = 1, k = 0; i < 10; i++)
    if (A[i] > A[k])
      k = i;

  return k;
}

// idx of min non-negative in A[0..10]
// -1 for error
int f_53(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, k;

  for (i = 0, k = -1; i < 10; i++) {
    if (A[i] < 0)
      continue;

    if (k == -1)
      k = i;
    else if (A[i] < A[k])
      k = i;
  }

  return k;
}

// same
// -1 for error
int f_54(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, k;

  for (i = 0, k = -1; i < 10; i++) {
    if (A[i] < 0)
      continue;

    if (k == -1 || A[i] < A[k])
      k = i;
  }

  return k;
}

// A | take 10 | filter > 0 | count
// -1 for error
int f_55(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s;

  for (i = 0, s = 0; i < 10; i++)
    if (A[i] > 0)
      s++;

  return s;
}

// negative-to-positive transitions in A[0..10] part 2
// -1 for error
int f_56(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s;

  for (i = 1, s = 0; i < 10; i++)
    if (A[i] > 0 && A[i - 1] < 0)
      s++;

  return s;
}

// longest run of growing numbers in A[0..9]
// -1 for error
int f_57(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s, k;

  for (i = 1, s = 0, k = 0; i < 10; i++) {
    if (A[i - 1] < A[i])
      k++;
    else {
      if (k > s)
        s = k;

      k = 0;
    }
  }

  return s;
}

// negative-to-positive transitions in A[0..10] part 3
// -1 for error
int f_58(int const *A, int n) {
  if (n < 10)
    return -1;

  int i, s, k;

  for (i = 0, s = 0, k = 0; i < 10; i++)
    if (A[i] < 0)
      k = 1;
    else {
      if (k == 1)
        s++;
      k = 0;
    }

  return s;
}

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++) {
    if (buf[i] == 0)
      break;
    printf("%d ", buf[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    eprintf("Usage: %s <num>", argv[0]);
    return EXIT_FAILURE;
  }

  int arg = 65; // can be anything really
  int arg2 = 100;

#define BUF_LEN 100 // see f17 for why
  int *buf = malloc(BUF_LEN * sizeof(int));
  int *buf2 = malloc(BUF_LEN * sizeof(int));
  if (buf == NULL || buf2 == NULL) {
    eprintf("Alloc fault");
    exit(EXIT_FAILURE);
  } else {
    for (int i = 0; i < BUF_LEN; i++) {
      buf[i] = i + 1; // same ^
      buf2[i] = 2 * i + 1;
    }
  }

  int result;
  switch (strtol(argv[1], NULL, 10)) {
  case 13:
    result = f_13(arg);
    printf("%d", result);
    break;
  case 14:
    result = f_14(arg);
    printf("%d", result);
    break;
  case 15:
    result = f_15(arg);
    printf("%d", result);
    break;
  case 16:
    f_16(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 17:
    result = f_17(buf, BUF_LEN);
    if (result == -1)
      eprintf("f17 error");
    else
      print_buf(buf, BUF_LEN);
    break;
  case 18:
    f_18(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 19:
    f_19(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 20:
    f_20(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 21:
    f_21(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 22:
    f_22(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 23:
    f_23(buf, buf2, BUF_LEN);
    print_buf(buf2, BUF_LEN);
    break;
  case 24:
    f_24(buf, buf2, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 25:
    f_25(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 26:
    f_26(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 27:
    f_27(buf, BUF_LEN, arg);
    print_buf(buf, BUF_LEN);
    break;
  case 28:
    result = f_28(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 29:
    result = f_29(buf, BUF_LEN, arg);
    printf("%d", result);
    break;
  case 30:
    result = f_30(buf, BUF_LEN, arg, arg2);
    if (result == -1)
      eprintf("f31 error");
    else
      print_buf(buf, BUF_LEN);
    break;
  case 31:
    result = f_31(buf, BUF_LEN);
    if (result == -1)
      eprintf("f31 error");
    else
      printf("%d", result);
    break;
  case 32:
    result = f_32(buf, BUF_LEN);
    if (result == -1)
      eprintf("f32 error");
    else
      printf("%d", result);
    break;
  case 33:
    result = f_33(buf, BUF_LEN);
    if (result == -1)
      eprintf("f33 error");
    else
      printf("%d", result);
    break;
  case 34:
    result = f_34(arg);
    printf("%d", result);
    break;
  case 35:
    f_35(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 36:
    result = f_36(buf, BUF_LEN);
    if (result == -1)
      eprintf("f36 error");
    else
      printf("%d", result);
    break;
  case 37:
    result = f_37(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 38:
    result = f_38(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 39:
    result = f_39(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 40:
    result = f_40(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 41:
    result = f_41(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 42:
    result = f_42(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 43:
    result = f_43(buf, BUF_LEN);
    printf("%d", result);
    break;
  case 44:
    f_44(buf, buf2, BUF_LEN);
    print_buf(buf2, BUF_LEN);
    break;
  case 45:
    f_45(buf, buf2, BUF_LEN);
    print_buf(buf, BUF_LEN);
    print_buf(buf2, BUF_LEN);
    break;
  case 46:
    f_46(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 47:
    result = f_47(buf, BUF_LEN, arg);
    if (result == -1)
      eprintf("f47 error");
    else
      print_buf(buf, BUF_LEN);
    break;
  case 48:
    f_48(buf, BUF_LEN);
    print_buf(buf, BUF_LEN);
    break;
  case 49:
    result = f_49(buf, BUF_LEN);
    if (result == -1)
      eprintf("f49 error");
    else
      printf("%d", result);
    break;
  case 50:
    result = f_50(buf, BUF_LEN);
    if (result == -1)
      eprintf("f50 error");
    else
      printf("%d", result);
    break;
  case 51:
    result = f_51(buf, BUF_LEN);
    if (result == -1)
      eprintf("f51 error");
    else
      printf("%d", result);
    break;
  case 52:
    result = f_52(buf, BUF_LEN);
    if (result == -1)
      eprintf("f52 error");
    else
      printf("%d", result);
    break;
  case 53:
    result = f_53(buf, BUF_LEN);
    if (result == -1)
      eprintf("f53 error");
    else
      printf("%d", result);
    break;
  case 54:
    result = f_54(buf, BUF_LEN);
    if (result == -1)
      eprintf("f54 error");
    else
      printf("%d", result);
    break;
  case 55:
    result = f_55(buf, BUF_LEN);
    if (result == -1)
      eprintf("f55 error");
    else
      printf("%d", result);
    break;
  case 56:
    result = f_56(buf, BUF_LEN);
    if (result == -1)
      eprintf("f56 error");
    else
      printf("%d", result);
    break;
  case 57:
    result = f_57(buf, BUF_LEN);
    if (result == -1)
      eprintf("f57 error");
    else
      printf("%d", result);
    break;
  case 58:
    result = f_58(buf, BUF_LEN);
    if (result == -1)
      eprintf("f58 error");
    else
      printf("%d", result);
    break;
  default:
    eprintf("task must be 13 to 58");
    return EXIT_FAILURE;
  }

  free(buf);
  free(buf2);

  return EXIT_SUCCESS;
}
