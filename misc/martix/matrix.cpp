#ifndef MATRIX
#define MATRIX

#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
template <int n, int m> class Matrix {
public:
  std::vector<std::vector<double>> mat; // uncertain size array
  // Constructor
  Matrix() = default; // default constructor
  constexpr int getRow() { return n; }
  constexpr int getColumn() { return m; }
  void print(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout<<this->mat[i][j] <<" ";
        }
        std::cout <<"\n";
    }
  }
  Matrix(std::vector<std::vector<double>> input) : mat(input){};
  Matrix(const double v[n][m]) {
    for (int i = 0; i < n; i++) {
      std::vector<double> col;
      col.insert(col.end(), &v[i][0], &v[i][m]);
      mat.push_back(col);
    }
  }

  Matrix(std::initializer_list<std::initializer_list<double>> v) {
    if(v.size()<n || v.begin()->size()<m)
        throw std::string("size not match");
    for (int i = 0; i < n; i++) {
      std::vector<double> col;
      col.insert(col.end(), (v.begin() + i)->begin(), (v.begin() + i)->end());
    //   std::cout << col[0] << "\n";
      mat.push_back(col);
    }
  };
  Matrix(const Matrix &input)
      : mat(input.mat){}; // copy constructor, pass by reference
  ~Matrix(){};            // destructor
  Matrix &operator=(const Matrix &input){
    this->mat=input.mat;
    return *this;
  }
  Matrix &operator=(std::initializer_list<std::initializer_list<double>> input) {
    for (int i = 0; i < n; i++) {
      std::vector<double> col;
      col.insert(col.end(), (input.begin() + i)->begin(),
                 (input.begin() + i)->end());
      mat[i] = col;
    }
    return *this;
  }
  Matrix &operator=(std::vector<std::vector<double>> &input) {
    for (int i = 0; i < n; i++) {
      std::vector<double> col;
      col.insert(col.end(), &input[i][0], &input[i][m]);
      mat.push_back(col);
    }
    return *this;
  }
  template <int in,int im>
  Matrix operator+(const Matrix<in,im> &input){
    std::vector<std::vector<double>> nmat; // uncertain size array
    for(int i=0;i<n;i++){
        nmat.push_back(std::vector<double>(m,0));
        for(int j=0;j<m;j++){
            nmat[i][j]=this->mat[i][j]+input.mat[i][j];
        }
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  template <int in,int im>
  Matrix operator-(const Matrix<in,im> &input){
    std::vector<std::vector<double>> nmat; // uncertain size array
    for(int i=0;i<n;i++){
        nmat.push_back(std::vector<double>(m,0));
        for(int j=0;j<m;j++){
            nmat[i][j]=this->mat[i][j]-input.mat[i][j];
        }
    }
    Matrix<n, m> out(nmat);
    return out;
  };
  template <int in,int im>
  Matrix<n,im> operator*(const Matrix<in,im> &input) {
    if(m!=in)
        throw std::string("size no match");
    std::vector<std::vector<double>> nmat; // uncertain size array
    for(int i=0;i<n;i++){
        nmat.push_back(std::vector<double>(im,0));
        for(int j=0;j<im;j++){
            for(int k=0;k<m;k++){
                nmat[i][j]+=this->mat[i][k]*input.mat[k][j];
            }
        }
    }
    Matrix<n, im> out(nmat);
    return out;
  }
  Matrix operator*(const double &input) {
    std::vector<std::vector<double>> nmat=this->mat; // uncertain size array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            nmat[i][j]*=2;
        }
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  Matrix<m,n> transpose() {
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
        nmat.push_back(std::vector<double>(0));
        for (int j = 0; j < m; j++) {
        nmat[i].push_back(mat[j][i]);
      }
    }
    Matrix< m,n> out(nmat);
    return out;
  }
  
};

#endif
int main() {
    // double te[2][2] = {{-2, 0}, {4, 2}};
    Matrix<2, 2> A({{2.0, -2.0}, {3.0, -5.0}});
    Matrix<2, 2> B({{-2, 0}, {4, 2}});
    Matrix<2, 3> C({{-1,2,0},{2,0,3}});
    Matrix<3, 2> E({{2,-1},{M_PI,(double)log10(2)},{-2,3}});
    Matrix<3, 3> F({{1,2,3},{2,3,4},{3,5,7}});
    Matrix<3, 3> I({{1,0,0},{0,1,0},{0,0,1}});
    // a.print();
    (A+B*2.0).print();
    E.transpose();
    (C-B*E.transpose()).print();
    (A.transpose()).print();

    //b
    Matrix<2,2> M=A*B;
    Matrix<2,2> N=B*A;

    //c
    Matrix<3, 2> P=C.transpose()*B.transpose();
    Matrix<3,2> Q=(B*C).transpose();

    //d

    return 0;
}
