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
  Matrix<2, 2> T({{6, 9}, {2, 3}});
  // a
  // printf("%lf\n", (A[0]).mat[0][0]);
  // Matrix<1, 2> ea = A.eigenValue();
  A.print();
  printf("%lf\n", (A - A.eye() * A.eigenValue().mat[0][1]).det());
  printf("\n");
  A.eigenValue().print();
  printf("\n");
  A.eigenVector().print();
  return 0;
}
