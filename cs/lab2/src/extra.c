#include <math.h>
#include <stdio.h>

#define eps 0.01
#define START 0.1
#define STEP 0.1
#define END 0.9

int main(int argc, char *argv[]) {
  double s, sn;
  int n;

  for (double x = START; x < END + STEP / 2; x += STEP) {
    printf("x = %.1f |", x);

    // f1
    // wolfram: Sum[Divide[Power[\(40)-x\(41),n],n factorial],{n,0,∞}]
    // converges to exp(-x)
    for (s = 0, sn = 1, n = 1; fabs(sn) > eps; n++) {
      s += sn;

      sn = -sn * x / n;
    }
    printf(" f1 = %f | exp(-x) = %f |", s, exp(-x));

    // f3
    // wolfram: Sum[Divide[Power[x,2n+1],\(40)2n+1\(41) factorial],{n,0,∞}]
    // converges to sinh(x)
    // there was a semicolon, changed to comma
    for (s = 0, sn = x, n = 1; fabs(sn) > eps; n += 2) {
      s += sn;

      sn = sn * x * x / (n * (n + 1));
    }
    printf(" f3 = %f | sinh(x) = %f\n", s, sinh(x));
  }
}
