// shell sort
void sort4(int A[], int n) {
  int m; // outside of for
  for (m = 1; m < n; m *= 2)
    ;
  for (m /= 2; m != 0; m /= 2)
    for (int k = 0; k < m; k++)
      for (int i = k + m; i < n; i += m)
        for (int j = i; j >= m && A[j] < A[j - m]; j -= m) {
          int cc = A[j];
          A[j] = A[j - m];
          A[j - m] = cc;
        }
}

// shaker sort
void sort8(int A[], int n) {
  int z = 1, a = 0, b = n - 1, i, last = 0;

  for (i = 0; a < b;) {
    if (A[i] > A[i + 1]) {
      int c = A[i];
      A[i] = A[i + 1];
      A[i + 1] = c;

      last = i;
    }

    i += z;
    if (i == b || i < a) {
      if (z > 0)
        i = b = last;
      else
        i = a = last + 1;
      z = -z;
    }
  }
}
