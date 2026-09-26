#define n 10

int main(int argc, char *argv[]) {
  int c[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i = 0, j;

  do {
    j = i + 1;
    while (j < n) {
      if (c[i] == c[j])
        return i;
      j++;
    }
    i++;
  } while (i < n - 1);
}
