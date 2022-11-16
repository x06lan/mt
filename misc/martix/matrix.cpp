#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
template <int n, int m> class Matrix {
public:
	std::vector<std::vector<double>> mat; // uncertain size array
	// Constructor
	Matrix() = default; // default constructor
	~Matrix(){};			// destructor
	constexpr int getRow() { return n; }
	constexpr int getColumn() { return m; }
	void print(){
		for (int i = 0; i < mat.size(); i++) {
			printf("[");
			for (int j = 0; j < mat[0].size(); j++) {
				// std::cout<<this->mat[i][j] <<" ";
				printf("%2.4lf ",this->mat[i][j]);
				if(j!=mat.size()-1)
					printf(",");
			}
			printf("]");
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
	Matrix &operator=(const Matrix &input){
		this->mat=input.mat;
		return *this;
	}
	Matrix &operator=(std::initializer_list<std::initializer_list<double>> input) {
		for (int i = 0; i < n; i++) {
			std::vector<double> col;
			col.insert(col.end(), (input.begin() + i)->begin(),(input.begin() + i)->end());
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
	bool operator==(const Matrix<in,im> &input){
		if(in!=n||im!=m)
			return false;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(this->mat[i][j]!=input.mat[i][j])
					return false;
			}
		}
		return true;
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
	template <int in,int im>
	Matrix<n,im> operator*(const Matrix<m,im> &&input) {
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
		for (int i = 0; i < m; i++) {
			nmat.push_back(std::vector<double>(0));
			for (int j = 0; j < n; j++) {
				nmat[i].push_back(mat[j][i]);
			}
		}
		Matrix< m,n> out(nmat);
		return out;
	}
	Matrix rref(){
		std::vector<std::vector<double>> nmat=this->mat; // uncertain size array
		int row=0;
		while(row<n){
			for(int i=row+1;i<n;i++){
				double v=0;
				if(nmat[i][row]!=0.0)
					v=nmat[i][row]/nmat[row][row];
				for(int j=0;j<m;j++){
					nmat[i][j]-=nmat[row][j]*v;
				}
			}
			row+=1;
		}
		int head[n];
		for(int i=0;i<n;i++){
			head[i]=-1;
			for(int j=0;j<n;j++){
				if(nmat[i][j]!=0){
					head[i]=j;
					break;
				}
			}
			double v=0;
			if(head[i]!=-1 ){
				v=nmat[i][head[i]];
				for(int j=0;j<m;j++){
					nmat[i][j]/=v;
				}
			}
		}
		row=1;
		while(row<n){
			if(head[row]==-1){
				row+=1;
				continue;
			}
			for(int i=row-1;i>=0;i--){
				double v=0;
				if(nmat[i][head[row]]!=0.0)
					v=nmat[i][head[row]]/nmat[row][head[row]];
				for(int j=0;j<m;j++){
					nmat[i][j]-=nmat[row][j]*v;
				}
			}
			row+=1;
		}
		Matrix< n,m> out(nmat);
		return out;
	}
	Matrix<n,m> invert(){
		std::vector<std::vector<double>> eye=this->eye().mat;
		std::vector<std::vector<double>> nmat=this->mat; // uncertain size array
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				nmat[i].push_back(eye[i][j]);
			}
		}
		Matrix< n,2*m> out(nmat);
		out=out.rref();
		for(int i=0;i<n;i++){
			nmat[i].clear();
			for(int j=0;j<m;j++){
				nmat[i].push_back(out.mat[i][m+j]);
			}
		}
		Matrix<n,m> nout(nmat);
		return nout;
	}
	Matrix eye(){
		std::vector<std::vector<double>> nmat; // uncertain size array
		for(int i=0;i<n;i++){
			nmat.push_back(std::vector<double>(m,0));
			if(i<m)
				nmat[i][i]=1;
		}
		Matrix<n,m> out(nmat);
		return out;
	}
};
#endif
int main() {
	Matrix<2, 2> A({{2.0, -2.0}, {3.0, -5.0}});
	Matrix<2, 2> B({{-2, 0}, {4, 2}});
	Matrix<2, 3> C({{-1,2,0},{2,0,3}});
	Matrix<3, 2> E({{2,-1},{M_PI,log10(2)},{-2,3}});
	Matrix<3, 3> F({{1,2,3},{2,3,4},{3,5,7}});
	Matrix<3, 3> I({{1,0,0},{0,1,0},{0,0,1}});
	//a
	printf("1.a:\n");
	printf("\nA+2*B=\n");
	(A+B*2.0).print();
	printf("\nC-B*E=\n");
	(C-B*E.transpose()).print();
	printf("\nA^T=\n");
	(A.transpose()).print();

	//b
	printf("\n1.b:\n");
	Matrix<2,2> M=A*B;
	Matrix<2,2> N=B*A;
	printf("M==N? \n");
	std::cout<< ((M==N)?"True":"False") <<"\n";

	//c
	printf("\n1.c:\n");
	Matrix<3,2> P=C.transpose()*B.transpose();
	Matrix<3,2> Q=(B*C).transpose();
	printf("P==Q? \n");
	std::cout<< ((P==Q)?"True":"False") <<"\n";

	//d
	printf("\n1.d:\n");
	printf("A is inverable \n");
	printf("A invert=\n");
	A.invert().print();

	//2
	printf("\n2:\n");
	Matrix<3,3> T({{1.0/6,1.0/2,1.0/3},{1.0/2,1.0/4,1.0/4},{1.0/3,1.0/4,5.0/12}});
	Matrix<3,3> T5=T;
	for(int i =1;i<5;i++)
		T5=T5*T;
	Matrix<3,3> T10=T5;
	for(int i =1;i<2;i++)
		T10=T10*T5;
	Matrix<3,3> T20=T10;
	for(int i =1;i<2;i++)
		T20=T20*T10;
	Matrix<3,3> T30=T10;
	for(int i =1;i<3;i++)
		T30=T30*T10;
	
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
