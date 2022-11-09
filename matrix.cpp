#include "matrix.h"
#include <exception>

using namespace std;

ostream &operator<<(ostream &os, const Matrix &matrix) {
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++)
      os << matrix.data[i][j] << " ";
    os << "\n";
  }
  return os;
}

/*
istream &operator>>(istream &is, const Matrix &matrix) {
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++)
      is >> matrix.data[i][j] << " ";
    is >> "\n";
  }
  return is;
}
*/

Matrix::Matrix(int m, int n, const std::vector<int> &data_as_one_vector) : m(m), n(n), data(m, std::vector<int>(n)) {
  int k = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      data[i][j] = data_as_one_vector[k++];
  }
}


void Matrix::set_data(const std::vector<int> &data_as_one_vector) {
    if (data_as_one_vector.size() != m * n) {
      std::cerr << "Invalid data!!!" << std::endl;
      return;
    }
    int k = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        data[i][j] = data_as_one_vector[k++];
      } 
    }
}


// 3
Matrix Matrix::operator+(const Matrix &second) const {
  if (m != second.m || n != second.n) {
    throw logic_error("Matrix sizes do not match!!!");
  }
  Matrix result(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[i][j] = data[i][j] + second.data[i][j];
  }
  return result;
}


// 4
Matrix Matrix::operator*(int a) const {
  Matrix result(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[i][j] = data[i][j] * a;
  }
  return result;
}


// 5 
Matrix Matrix::operator*(const Matrix &second) const {
  if (n != second.m) { 
    throw logic_error("Matrix sizes do not match!!!");
  }
  Matrix result(m, second.n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < second.n; j++) {
      for (int k = 0; k < n; k++)
        result.data[i][j] += data[i][k] * second.data[k][j];
    }
  }
  return result;
}


// 6
Matrix Matrix::transpose() const {
  Matrix result(n, m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[j][i] = data[i][j];
  }
  return result;
}


// 7
Matrix Matrix::nth_power(int power) const {
  Matrix result = *this;
  for (int k = 2; k <= power; k++) 
    result = result * (*this);
  return result;
}