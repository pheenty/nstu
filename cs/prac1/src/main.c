// https://cprog.netlify.app/book/2/2.5#%D0%B2%D0%BE%D0%BF%D1%80%D0%BE%D1%81%D1%8B-%D0%B1%D0%B5%D0%B7-%D0%BE%D1%82%D0%B2%D0%B5%D1%82%D0%BE%D0%B2

#include <stdio.h>
#include <stdlib.h>
#define eprintf(args...) fprintf(stderr, ##args)

int f_13(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    s = s + k;
  }

  return s;
}

int f_14(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    if (k > s)
      s = k;
  }

  return s;
}

int f_15(int a) {
  int n, s, k;

  for (n = a, s = 0; n != 0; n = n / 10) {
    k = n % 10;
    s = s * 10 + k;
  }

  return s;
}

void f_16(int *A, int a) {
  int i, n;

  for (i = 0, n = a; n != 0; i++, n = n / 10)
    ;

  for (A[i--] = -1, n = a; n != 0; i--, n = n / 10)
    A[i] = n % 10;
}

// -1 for error
int f_17(int *A, int len) {
  if (len < 30000) {
    return EXIT_FAILURE;
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

void f_20(int *A, int n) {
  int i, k, j;

  for (i = 1, k = 0; i < n; i++)
    if (A[i] > A[k])
      k = i;

  for (j = k; j < n - 1; j++)
    A[j] = A[j + 1];

  n--; // ??
}

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

void f_23(int *A, int *B, int n) {
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

void f_24(int *A, int *B, int n) {
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

void f_28(int *A, int n) {
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
}

void f_29(int *A, int n, int v) {
  int i;

  for (i = 0; i < n; i++)
    if (A[i] % v != 0) {
      v--;
      i = -1;
    }
}

void f_30(int *A, int n, int v, int m) {
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
}

// -1 for err
int f_31(int *c, int n) {
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = i + 1; j < n; j++)
      if (c[i] == c[j])
        return i;

  return EXIT_FAILURE;
}

// -1 for err
int f_32(int *c, int n) {
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

// -1 for err
int f_33(int *A, int n) {
  int s, i, k, j, b = -1;

  for (s = 0, i = 0; i < n - 1; i++)
    if (A[i] == A[i + 1]) {
      for (k = 2; i + k < n && A[i] == A[i + k]; k++)
        ;

      if (k > s)
        s = k, b = i;
    }

  return b;
}

int f_34(int n) {
  int k, m;

  for (k = 0, m = 1; m <= n; k++, m = m * 2)
    ;

  return k - 1;
}

void f_35(int *c, int n) {
  int k, i, j;

  for (i = 0, j = n - 1; i < j; i++, j--) {
    k = c[i];
    c[i] = c[j];
    c[j] = k;
  }
}

// -1 for err
int f_36(int *c, int n, int k1, int k2) {
  int i, j;

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

  return EXIT_FAILURE;
}

/*
void f_37() {

  for (s = 0, i = 0; i < n - 1; i++) {

    for (j = i + 1, m = 0; j < n; j++)

      if (c[i] == c[j])
        m++;

    if (m > s)
      s = m, b = i;
  }
}

void f_38() {

  for (i = k = m = 0; i < n - 1; i++)

    if (c[i] == c[i + 1])
      k++;

    else {

      if (k > m)
        m = k, b = i - k - 1;

      k = 0;
    }
}

void f_39() {

  for (s = 0, i = 0; i < n; i++) {

    if (A[i] < 0)
      continue;

    if (A[i] == 0)
      break;

    s = s + A[i];
  }
}

void f_40() {
  for (s = 0, i = 0; i < n && A[i] > 0; i++)
    s = s + A[i];
}

void f_41() {

  for (k = 0, s = 0, i = 0; i < n && k == 0; i++) {

    if (A[i] < 0)
      k = 1;

    s = s + A[i];
  }
}

void f_42() {

  for (s1 = 0, s2 = 0, i = 0, j = n - 1; i <= j;) {

    if (s1 < s2)
      s1 += A[i], i++;

    else
      s2 += A[j], j--;
  }

  return i;
}

void f_43() {

  for (s = 0, i = 0; i < n; i++) {

    if (i % 2 == 0)
      s = s + A[i];

    else
      s = s - A[i];
  }
}

void f_44() {

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

void f_45() {

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

void f_46() {

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

void f_47() {

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
}

void f_48() {

  for (i = 0; i < n - 1; i++)

    if (A[i] == A[i + 1]) {

      for (j = i; j < n - 2; j++)
        A[j] = A[j + 2];

      n = n - 2;

      i--;
    }
}

void f_49() {

  for (i = 0, k = -1; i < 10; i++) {

    if (A[i] < 0)
      continue;

    if (k == -1)
      k = i;

    else

        if (A[i] < A[k])
      k = i;
  }
}

void f_50() {

  for (i = 0, s = 0, k = 0; i < 10; i++)

    if (A[i] < 0)
      k = 1;

    else {

      if (k == 1)
        s++;

      k = 0;
    }
}

void f_51() {

  for (i = 0, s = 0; i < 10; i++)

    if (A[i] > s)
      s = A[i];
}

void f_52() {

  for (i = 1, k = 0; i < 10; i++)

    if (A[i] > A[k])
      k = i;
}

void f_53() {

  for (i = 0, k = -1; i < 10; i++)

  {
    if (A[i] < 0)
      continue;

    if (k == -1)
      k = i;

    else

        if (A[i] < A[k])
      k = i;
  }
}

void f_54() {

  for (i = 0, k = -1; i < 10; i++)

  {
    if (A[i] < 0)
      continue;

    if (k == -1 || A[i] < A[k])
      k = i;
  }
}

void f_55() {

  for (i = 0, s = 0; i < 10; i++)

    if (A[i] > 0)
      s++;
}

void f_56() {

  for (i = 1, s = 0; i < 10; i++)

    if (A[i] > 0 && A[i - 1] < 0)
      s++;
}

void f_57() {

  for (i = 1, s = 0, k = 0; i < 10; i++) {

    if (A[i - 1] < A[i])
      k++;

    else {

      if (k > s)
        s = k;

      k = 0;
    }
  }
}

void f_58() {

  for (i = 0, s = 0, k = 0; i < 10; i++)

    if (A[i] < 0)
      k = 1;

    else

    {
      if (k == 1)
        s++;
      k = 0;
    }
}
*/

void print_buf(int *buf, int len) {
  for (int i = 0; i < len; i++)
    printf("%d  ", buf[i]);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    eprintf("Usage: prac1 <num>");
    return EXIT_FAILURE;
  }

  int result;

  int arg = 10; // can be anything really
  int arg2 = 65;

  int buf_len = 30000; // see f17 for why
  int *buf = malloc(buf_len * sizeof(int));
  int *buf2 = malloc(buf_len * sizeof(int));
  if (buf == NULL || buf2 == NULL) {
    eprintf("Alloc fault");
    return EXIT_FAILURE;
  } else {
    for (int i = 0; i < buf_len; i++) {
      buf[i] = 1; // same ^
      buf2[i] = 2;
    }
  }

  long fn = strtol(argv[1], NULL, 10);
  // if (errno != 0) {
  //   return EXIT_FAILURE;
  // }

  switch (fn) {
  case 13:
    result = f_13(arg);
    printf("s = %d", result);
    break;
  case 14:
    result = f_14(arg);
    printf("s = %d", result);
    break;
  case 15:
    result = f_15(arg);
    printf("s = %d", result);
    break;
  case 16:
    f_16(buf, buf_len);
    print_buf(buf, buf_len);
    break;
  case 17:
    result = f_17(buf, buf_len);
    if (result == 0)
      eprintf("f17 error");
    else
      print_buf(buf, buf_len);
    break;
  case 18:
    f_18(buf, buf_len);
    print_buf(buf, buf_len);
    break;
  case 19:
    f_19(buf, buf_len);
    print_buf(buf, buf_len);
    break;
  case 20:
    f_20(buf, buf_len);
    break;
  case 21:
    f_21(buf, buf_len);
    break;
  case 22:
    f_22(buf, buf_len);
    break;
  case 23:
    f_23(buf, buf2, buf_len);
    break;
  case 24:
    f_24(buf, buf2, buf_len);
    break;
  case 25:
    f_25(buf, buf_len);
    break;
  case 26:
    f_26(buf, buf_len);
    break;
  case 27:
    f_27(buf, buf_len, arg);
    break;
  case 28:
    f_28(buf, buf_len);
    break;
  case 29:
    f_29(buf, buf_len, arg);
    break;
  case 30:
    f_30(buf, buf_len, arg, arg2);
    break;
  case 31:
    f_31(buf, buf_len);
    break;
  case 32:
    f_32(buf, buf_len);
    break;
  case 33:
    f_33(buf, buf_len);
    break;
  case 34:
    f_34(arg);
    break;
  case 35:
    f_35(buf, buf_len);
    break;
  case 36:
    f_36(buf, buf_len, arg, arg2);
    break;
    /*
  case 37:
    f_37();
    break;
case 38:
        f_38();
        break;
      case 39:
        f_39();
        break;
      case 40:
        f_40();
        break;
      case 41:
        f_41();
        break;
      case 42:
        f_42();
        break;
      case 43:
        f_43();
        break;
      case 44:
        f_44();
        break;
      case 45:
        f_45();
        break;
      case 46:
        f_46();
        break;
      case 47:
        f_47();
        break;
      case 48:
        f_48();
        break;
      case 49:
        f_49();
        break;
      case 50:
        f_50();
        break;
      case 51:
        f_51();
        break;
      case 52:
        f_52();
        break;
      case 53:
        f_53();
        break;
      case 54:
        f_54();
        break;
      case 55:
        f_55();
        break;
      case 56:
        f_56();
        break;
      case 57:
        f_57();
        break;
      case 58:
        f_58();
        break; */
  default:
    eprintf("task must be 13 to 58");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
