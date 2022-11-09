#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <vector>
#include <iostream>

class Matrix {
public:
  Matrix(int m = 0, int n = 0) : m(m), n(n), data(m, std::vector<int>(n)) {}
  Matrix(int m, int n, const std::vector<int> &data_as_one_vector);
  int get_m() const { return m; }
  int get_n() const { return n; }
  void set_data(const std::vector<int> &data_as_one_vector);
  Matrix operator+(const Matrix &second) const;
  Matrix operator*(int a) const;
  Matrix operator*(const Matrix &second) const;
  Matrix transpose() const;
  Matrix nth_power(int power) const;
  const std::vector<int> &operator[](int idx) const {
    return data[idx];
  }

private:
  int m;
  int n;
  std::vector<std::vector<int>> data;

  friend std::ostream &operator<<(std::ostream &, const Matrix &);
  //friend std::istream &operator>>(std::istream &, const Matrix &);
};
#endif