#include "./matrix.cpp"
#include <stdio.h>
int main() {
  Matrix<2, 2> A({{-1, 2}, {0, 2}});
  Matrix<2, 2> B({{1, 6}, {5, 2}});
  Matrix<2, 2> C({{1, 2}, {2, 4}});
  Matrix<2, 2> V({{7, 2}, {-4, 1}});
  Matrix<2, 2> W({{3, 1}, {-1, 1}});
  Matrix<2, 2> X({{1, 2}, {3, 4}});
  Matrix<2, 2> Z({{0, 0}, {0, 0}});
  // a
  printf("%lf\n", (A[0]).mat[0][0]);
  return 0;
}
