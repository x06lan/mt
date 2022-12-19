#include "./matrix.cpp"
#include <stdio.h>
int main() {
  Matrix<2, 2> A({{2.0, -2.0}, {3.0, -5.0}});
  Matrix<2, 2> B({{-2, 0}, {4, 2}});
  Matrix<2, 3> C({{-1, 2, 0}, {2, 0, 3}});
  Matrix<3, 2> E({{2, -1}, {M_PI, log10(2)}, {-2, 3}});
  Matrix<3, 3> F({{1, 2, 3}, {2, 3, 4}, {3, 5, 7}});
  Matrix<3, 3> I({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
  // a
  printf("1.a:\n");
  printf("\nA+2*B=\n");
  (A + B * 2.0).print();
  printf("\nC-B*E=\n");
  (C - B * E.transpose()).print();
  printf("\nA^T=\n");
  (A.transpose()).print();

  // b
  printf("\n1.b:\n");
  Matrix<2, 2> M = A * B;
  Matrix<2, 2> N = B * A;
  printf("M==N? \n");
  std::cout << ((M == N) ? "True" : "False") << "\n";

  // c
  printf("\n1.c:\n");
  Matrix<3, 2> P = C.transpose() * B.transpose();
  Matrix<3, 2> Q = (B * C).transpose();
  printf("P==Q? \n");
  std::cout << ((P == Q) ? "True" : "False") << "\n";

  // d
  printf("\n1.d:\n");
  printf("A is inverable \n");
  printf("A invert=\n");
  A.invert().print();

  // 2
  printf("\n2:\n");
  Matrix<3, 3> T({{1.0 / 6, 1.0 / 2, 1.0 / 3},
                  {1.0 / 2, 1.0 / 4, 1.0 / 4},
                  {1.0 / 3, 1.0 / 4, 5.0 / 12}});
  Matrix<3, 3> T5 = T;
  for (int i = 1; i < 5; i++)
    T5 = T5 * T;
  Matrix<3, 3> T10 = T5;
  for (int i = 1; i < 2; i++)
    T10 = T10 * T5;
  Matrix<3, 3> T20 = T10;
  for (int i = 1; i < 2; i++)
    T20 = T20 * T10;
  Matrix<3, 3> T30 = T10;
  for (int i = 1; i < 3; i++)
    T30 = T30 * T10;

  printf("T^5=\n");
  (T5).print();
  printf("T^10=\n");
  (T10).print();
  printf("T^20=\n");
  (T20).print();
  printf("T^30=\n");
  (T30).print();
  return 0;
}
