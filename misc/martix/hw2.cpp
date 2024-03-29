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
  A.eigenValue()[0].print();
  printf("eigenVector for λ1 is\n");
  A.eigenVector().print();
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
  C.eigenVector()[0].print();
  printf("[All nonzero vectors]\n");
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
  //W.eigenValue().print();
  printf("eigenVector for λ1 is\n");
  W.eigenVector()[0].print();
  //W.eigenVector().print();
  printf("\n");

  printf("X:\n");
  printf("eigenValue λ1,λ2 is\n");
  X.eigenValue().print();
  printf("eigenVector for λ1,λ2 is\n");
  X.eigenVector().print();
  printf("\n");

  printf("Z:\n");
  printf("eigenValue λ1 is\n");
  printf("[%.4lf ]\n", Z.eigenValue().mat[0][0]);
  printf("eigenVector λ1\n");
  printf("All nonzero vectors\n");
  printf("\n");
	//printf("T:\n");
	//printf("eigenValue λ1,λ2 is\n");
	//T.eigenValue().print();
	//printf("eigenVector for λ1,λ2 is\n");
	//T.eigenVector().print();
	//printf("\n");
  return 0;
}
