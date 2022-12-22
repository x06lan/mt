#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
template <int n, int m> class Matrix {
public:
  std::vector<std::vector<double>> mat; // uncertain size array
  // Constructor
  Matrix() = default; // default constructor
  ~Matrix(){};        // destructor
  constexpr int getRow() { return n; }
  constexpr int getColumn() { return m; }
  void print() {
    for (int i = 0; i < mat.size(); i++) {
      printf("[");
      for (int j = 0; j < mat[0].size(); j++) {
        printf("%2.4lf ", this->mat[i][j]);
        if (j != this->mat[0].size() - 1)
          printf(",");
      }
      printf("]");
      std::cout << "\n";
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
    if (v.size() < n || v.begin()->size() < m)
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
  Matrix &operator=(const Matrix &input) {
    this->mat = input.mat;
    return *this;
  }
  Matrix &
  operator=(std::initializer_list<std::initializer_list<double>> input) {
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
  template <int in, int im> bool operator==(const Matrix<in, im> &input) {
    if (in != n || im != m)
      return false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (this->mat[i][j] != input.mat[i][j])
          return false;
      }
    }
    return true;
  }
  template <int in, int im> Matrix operator+(const Matrix<in, im> &input) {
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
      nmat.push_back(std::vector<double>(m, 0));
      for (int j = 0; j < m; j++) {
        nmat[i][j] = this->mat[i][j] + input.mat[i][j];
      }
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  template <int in, int im> Matrix operator-(const Matrix<in, im> &input) {
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
      nmat.push_back(std::vector<double>(m, 0));
      for (int j = 0; j < m; j++) {
        nmat[i][j] = this->mat[i][j] - input.mat[i][j];
      }
    }
    Matrix<n, m> out(nmat);
    return out;
  };
  template <int in, int im>
  Matrix<n, im> operator*(const Matrix<in, im> &input) {
    if (m != in)
      throw std::string("size no match");
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
      nmat.push_back(std::vector<double>(im, 0));
      for (int j = 0; j < im; j++) {
        for (int k = 0; k < m; k++) {
          nmat[i][j] += this->mat[i][k] * input.mat[k][j];
        }
      }
    }
    Matrix<n, im> out(nmat);
    return out;
  }
  template <int in, int im>
  Matrix<n, im> operator*(const Matrix<m, im> &&input) {
    if (m != in)
      throw std::string("size no match");
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
      nmat.push_back(std::vector<double>(im, 0));
      for (int j = 0; j < im; j++) {
        for (int k = 0; k < m; k++) {
          nmat[i][j] += this->mat[i][k] * input.mat[k][j];
        }
      }
    }
    Matrix<n, im> out(nmat);
    return out;
  }
  Matrix operator*(const double &input) {
    std::vector<std::vector<double>> nmat = this->mat; // uncertain size array
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        nmat[i][j] *= 2;
      }
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  Matrix<1, m> operator[](const int &input) {
    Matrix<1, m> out({this->mat[input]});
    return out;
  }
  Matrix<m, n> transpose() {
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < m; i++) {
      nmat.push_back(std::vector<double>(0));
      for (int j = 0; j < n; j++) {
        nmat[i].push_back(mat[j][i]);
      }
    }
    Matrix<m, n> out(nmat);
    return out;
  }
  Matrix rref() {
    std::vector<std::vector<double>> nmat = this->mat; // uncertain size array
    int row = 0;
    while (row < n) {
      for (int i = row + 1; i < n; i++) {
        double v = 0;
        if (nmat[i][row] != 0.0)
          v = nmat[i][row] / nmat[row][row];
        for (int j = 0; j < m; j++) {
          nmat[i][j] -= nmat[row][j] * v;
        }
      }
      row += 1;
    }
    int head[n];
    for (int i = 0; i < n; i++) {
      head[i] = -1;
      for (int j = 0; j < n; j++) {
        if (nmat[i][j] != 0) {
          head[i] = j;
          break;
        }
      }
      double v = 0;
      if (head[i] != -1) {
        v = nmat[i][head[i]];
        for (int j = 0; j < m; j++) {
          nmat[i][j] /= v;
        }
      }
    }
    row = 1;
    while (row < n) {
      if (head[row] == -1) {
        row += 1;
        continue;
      }
      for (int i = row - 1; i >= 0; i--) {
        double v = 0;
        if (nmat[i][head[row]] != 0.0)
          v = nmat[i][head[row]] / nmat[row][head[row]];
        for (int j = 0; j < m; j++) {
          nmat[i][j] -= nmat[row][j] * v;
        }
      }
      row += 1;
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  Matrix<n, m> invert() {
    std::vector<std::vector<double>> eye = this->eye().mat;
    std::vector<std::vector<double>> nmat = this->mat; // uncertain size array
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        nmat[i].push_back(eye[i][j]);
      }
    }
    Matrix<n, 2 * m> out(nmat);
    out = out.rref();
    for (int i = 0; i < n; i++) {
      nmat[i].clear();
      for (int j = 0; j < m; j++) {
        nmat[i].push_back(out.mat[i][m + j]);
      }
    }
    Matrix<n, m> nout(nmat);
    return nout;
  }
  Matrix eye() {
    std::vector<std::vector<double>> nmat; // uncertain size array
    for (int i = 0; i < n; i++) {
      nmat.push_back(std::vector<double>(m, 0));
      if (i < m)
        nmat[i][i] = 1;
    }
    Matrix<n, m> out(nmat);
    return out;
  }
  // only 2x2 work
  double det() {
    std::vector<std::vector<double>> nmat = this->mat; // uncertain size array
    return nmat[0][0] * nmat[1][1] - nmat[0][1] * nmat[1][0];
  }
  // only 2x2 work
  Matrix<1, m> eigenValue() {
    std::vector<std::vector<double>> nmat = this->mat;

    // hardcode ax^2+bx+c=0;
    double a = 1;
    double b = -(nmat[0][0] + nmat[1][1]);
    double c = nmat[0][0] * nmat[1][1] - nmat[0][1] * nmat[1][0];
    if (b * b - 4 * a * c < 0)
      return Matrix<1, m>({{NAN, NAN}});
    double d = pow(b * b - 4 * a * c, 0.5);
    if (fabs(d) < 0.00001)
      return Matrix<1, m>({{-b / (2 * a), NAN}});

    return Matrix<1, m>({{(-b + d) / (2 * a), (-b - d) / (2 * a)}});
  }
  // only 2x2 work
  Matrix eigenVector() {
    Matrix<1, m> eigenValue = this->eigenValue();
    std::vector<std::vector<double>> s;
    for (int i = 0; i < eigenValue.getColumn(); i++) {
      std::vector<std::vector<double>> nmat = this->mat;
      for (int j = 0; j < n; j++) {
        nmat[j][j] -= eigenValue.mat[0][i];
      }
      Matrix ss(nmat);
      ss = ss.rref();
      s.push_back({});
	  //rref may not sort by pivot columns
	  if(ss.mat[0][1]!=0.0){
		  s[i].push_back(ss.mat[0][1]);
		  s[i].push_back(ss.mat[0][0]);
		}
	  else{
		  s[i].push_back(ss.mat[1][1]);
		  s[i].push_back(ss.mat[1][0]);
		}
    }
    return Matrix(s).transpose();
  }
};
#endif
