#include <stdio.h>

int _foo(int n, int n2, int n1) {
  if (n == 0) {
    return n1;
  } else if (n == 1) {
    return n2;
  } else if (n == 2) {
    return 2;
  } else if (n == 3) {
    return 7;
  } else {
    // Plugged in the given formula
    return _foo((n - 1), n1, n2) + _foo((n - 2), n1, n2) + _foo((n - 3), n1, n2) - _foo(n - 4, n1, n2) + 1;
  }
}

int foo(int n) {
  return _foo(n, 3, 6);
}

int main() {
  int n;
  printf("Enter a value for n: ");
  scanf("%d", &n);
  printf("Foo(%d) = %d\n", n, foo(n));
  return 0;
}
