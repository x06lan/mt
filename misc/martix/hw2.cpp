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
  // A.print();
  printf("A:\n");
  printf("zero vector cant be eigenVector by definetion\n");
  printf("eigenValue λ1 is\n");
  printf("[%.4lf ]\n", A.eigenValue().mat[0][0]);
  // A.eigenValue()[0].print();
  printf("eigenVector for λ1 is\n");
  A.eigenVector()[0].print();
  // A.eigenVector().print();
  printf("\n");

  printf("B:\n");
  printf("eigenValue λ1,λ2 is\n");
  B.eigenValue().print();
  printf("eigenVector for λ1,λ2 is\n");
  B.eigenVector().print();
  printf("\n");

  printf("C:\n");
  printf("eigenValue λ1,λ2 is\n");
  C.eigenValue().print();
  printf("eigenVector for λ1,λ2 is\n");
  C.eigenVector().print();
  printf("\n");

  printf("V:\n");
  printf("eigenValue λ1,λ2 is\n");
  V.eigenValue().print();
  printf("eigenVector for λ1,λ2 is\n");
  V.eigenVector().print();
  printf("\n");

  printf("W:\n");
  printf("λ1==λ2\n");
  printf("eigenValue λ1 is\n");
  printf("[%.4lf ]\n", W.eigenValue().mat[0][0]);
  printf("eigenVector for λ1 is\n");
  W.eigenVector()[0].print();
  printf("\n");

  printf("X:\n");
  printf("eigenValue λ1,λ2 is\n");
  X.eigenValue().print();
  printf("eigenVector for λ1,λ2 is\n");
  B.eigenVector().print();
  printf("\n");

  printf("Z:\n");
  printf(
      "zero vector cant be eigenVector by definetion\nso not have eigenValue "
      "and eigenVector");
  // printf("eigenValue is\n");
  // Z.eigenValue().print();
  // printf("eigenVector is\n");
  // Z.eigenVector()[0].print();
  printf("\n");
  return 0;
}
