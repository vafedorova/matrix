#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <vector>
#include <iostream>
#include <exception>

template<typename T>
class Matrix {
public:
  Matrix(int m = 0, int n = 0) : m(m), n(n), data(m, std::vector<T>(n)) {}
  Matrix(int m, int n, const std::vector<T> &data_as_one_vector);
  int get_m() const { return m; }
  int get_n() const { return n; }
  void set_data(const std::vector<T> &data_as_one_vector);
  Matrix<T> operator+(const Matrix<T> &second) const;
  Matrix<T> operator*(int a) const;
  Matrix<T> operator*(const Matrix<T> &second) const;
  Matrix<T> transpose() const;
  T det() const;
  const std::vector<T> &operator[](int idx) const {
    return data[idx];
  }

private:
  int m;
  int n;
  std::vector<std::vector<T>> data;

  Matrix<T> submatrix(int i) const {
    std::vector<T> new_data;
    for (int j = 1; j < m; j++) {
      for (int k = 0; k < n; k++) {
        if (k != i) {
          new_data.push_back(data[j][k]);
        }
      }
    }
    return Matrix(m - 1, n - 1, new_data);
  }
  template<typename TT> friend std::ostream &operator<<(std::ostream &, const Matrix<TT> &);
  template<typename TT> friend std::istream &operator>>(std::istream &, Matrix<TT> &);
};


template<typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix) {
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++)
      os << matrix.data[i][j] << " ";
    os << "\n";
  }
  return os;
}


template<typename T>
std::istream &operator>>(std::istream &is, Matrix<T> &matrix) {
  for (int i = 0; i < matrix.m; i++) {
    for (int j = 0; j < matrix.n; j++)
      is >> matrix.data[i][j];
  }
  return is;
}


template<typename T>
Matrix<T>::Matrix(int m, int n, const std::vector<T> &data_as_one_vector) : m(m), n(n), data(m, std::vector<T>(n)) {
  int k = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      data[i][j] = data_as_one_vector[k++];
  }
}


template<typename T>
void Matrix<T>::set_data(const std::vector<T> &data_as_one_vector) {
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
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &second) const {
  if (m != second.m || n != second.n) {
    throw std::logic_error("Matrix sizes do not match!!!");
  }
  Matrix<T> result(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[i][j] = data[i][j] + second.data[i][j];
  }
  return result;
}


// 4
template<typename T>
Matrix<T> Matrix<T>::operator*(int a) const {
  Matrix result(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[i][j] = data[i][j] * a;
  }
  return result;
}


// 5 
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &second) const {
  if (n != second.m) { 
    throw std::logic_error("Matrix sizes do not match!!!");
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
template<typename T>
Matrix<T> Matrix<T>::transpose() const {
  Matrix<T> result(n, m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) 
      result.data[j][i] = data[i][j];
  }
  return result;
}


// 7
template<typename T>
Matrix<T> nth_power(Matrix<T> a, int power) {
  if (power == 1)
    return a;
  if (power % 2)
    return a * nth_power(a, power - 1);
  Matrix<T> b = nth_power(a, power / 2);
  return b * b;
}


//8
template<typename T>
T Matrix<T>::det() const {
  if (m != n) {
    throw std::logic_error("Determinant exists only for square matrix!!!");
  }
  if (n == 1) {
    return (*this)[0][0];
  }
  if (n == 2) {
    return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
  }
  T result = 0;
  int sgn = 1;
  for (int i = 0; i < n; i++) {
    result += (*this)[0][i] * submatrix(i).det() * sgn;
    sgn *= -1;
  }
  return result;
}
#endif