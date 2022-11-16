#include <unordered_map>
#include "menu.h"
#include <exception>

using namespace std;

std::unordered_map<std::string, Matrix<int>> memory_map;

// 1
void enter_matrix() {
  cout << "Enter the name of the matrix: ";
  string matrix_name;
  cin >> matrix_name;
  cout << "Enter matrix sizes: \n";
  cout << "\tm = ";
  int m;
  cin >> m;
  cout << "\tn = ";
  int n;
  cin >> n;
  vector<int> data(m * n);
  int k = 0;
  for (int i = 1; i <= m; ++i) {
    cout << "Enter matrix row #" << i << "\n";
    for (int j = 0; j < n; ++j)
      cin >> data[k++];
  }
  memory_map[matrix_name] = Matrix<int>(m, n, data);
}


// 1, 2
Matrix<int> *choose_matrix_from_map(string &matrix_name) {
  if (memory_map.empty()) {
    cerr << "---\nNo matrices entered yet! Please, enter the matrix first!\n";
    cout << "Do you want to enter new matrix now? (1 = yes / 0 = no)\n";
    int ans;
    cin >> ans;
    if (ans) {
      enter_matrix();
    }
    matrix_name = memory_map.begin()->first;
    return &(memory_map.begin()->second);
  }
  for (const auto &kvp : memory_map) {
    cout << kvp.first << " ";
  }
  cout << "\n";
  cin >> matrix_name;
  if (memory_map.find(matrix_name) == memory_map.end()) {
    cerr << "Unknown matrix name! Please, enter the matrix first!\n";
    return 0;
  }
  return &(memory_map[matrix_name]);
}


// 2
void show_matrix() {
  cout << "Choose matrix to show: ";
  string m_name;
  Matrix<int> *m = choose_matrix_from_map(m_name);
  if (m)
    cout << *m;
}


// 3
void add_matrices() {
  cout << "Choose matrices to add:\n";
  string m1_name, m2_name;
  cout << "First matrix: ";
  Matrix<int> *m1 = 0;
  while (!(m1 = choose_matrix_from_map(m1_name))) {
    ;
  }
  cout << *m1;
  cout << "Second matrix: ";
  Matrix<int> *m2 = 0;
  while (!(m2 = choose_matrix_from_map(m2_name))) {
    ;
  }
  cout << *m2;
  try {
    Matrix<int> result_matrix = *m1 + *m2;
    cout << "Sum: " << m1_name << " + " << m2_name << " =\n" << result_matrix;
    cout << "Do you want to save " << m1_name << " + " << m2_name
         << "? (1 = yes / 0 = no)\n";
    int ans;
    cin >> ans;
    if (ans) {
      cout << "Enter the name of the matrix: ";
      string matrix_name;
      cin >> matrix_name;
      memory_map[matrix_name] = result_matrix;
    }
  }
  catch (const std::exception &ex) {
    cerr << ex.what() << "\n";
  }
}


// 4
void muptiply_by_number() {
  int a;
  cout << "Enter a number: ";
  cin >> a;
  string m1_name;
  cout << "Choose matrix: ";
  Matrix<int> *m1 = 0;
  while (!(m1 = choose_matrix_from_map(m1_name))) {
    ;
  }
  cout << *m1;
  Matrix<int> result_matrix = *m1 * a;
  cout << "Result: " << m1_name << " * " << a << " =\n" << result_matrix;
  cout << "Do you want to save " << m1_name << " * " << a
       << "? (1 = yes / 0 = no)\n";
  int ans;
  cin >> ans;
  if (ans) {
    cout << "Enter the name of the matrix: ";
    string matrix_name;
    cin >> matrix_name;
    memory_map[matrix_name] = result_matrix;
  }
}


// 5
void multiply_two_matrices() {
  cout << "Choose matrices to multiply:\n";
  string m1_name, m2_name;
  cout << "First matrix: ";
  Matrix<int> *m1 = 0;
  while (!(m1 = choose_matrix_from_map(m1_name))) {
    ;
  }
  cout << *m1;
  cout << "Second matrix: ";
  Matrix<int> *m2 = 0;
  while (!(m2 = choose_matrix_from_map(m2_name))) {
    ;
  }
  cout << *m2;
  try {
    Matrix<int> result_matrix = *m1 * *m2;
    cout << "Multiply: " << m1_name << " * " << m2_name << " =\n" << result_matrix;
    cout << "Do you want to save " << m1_name << " * " << m2_name
         << "? (1 = yes / 0 = no)\n";
    int ans;
    cin >> ans;
    if (ans) {
      cout << "Enter the name of the matrix: ";
      string matrix_name;
      cin >> matrix_name;
      memory_map[matrix_name] = result_matrix;
    }
  }
  catch (const std::exception &ex) {
    cerr << ex.what() << "\n";
  }
}


// 6
void transpose_matrix() {
  cout << "Choose matrix to transpose:\n";
  string m1_name;
  cout << "Matrix: ";
  Matrix<int> *m1 = 0;
  while (!(m1 = choose_matrix_from_map(m1_name))) {
    ;
  }
  cout << *m1;
  Matrix<int> result_matrix = m1->transpose(); 
  cout << "(" << m1_name << ")^T =\n" << result_matrix;
  cout << "Do you want to save (" << m1_name
       << ")^T? (1 = yes / 0 = no)\n";
  int ans;
  cin >> ans;
  if (ans) {
    cout << "Enter the name of the matrix: ";
    string matrix_name;
    cin >> matrix_name;
    memory_map[matrix_name] = result_matrix;
  }
}


// 7
void nth_power_matrix() {
  int power;
  cout << "Enter a number: ";
  cin >> power;
  string m1_name;
  cout << "Choose matrix: ";
  Matrix<int> *m1 = 0;
  while (!(m1 = choose_matrix_from_map(m1_name))) {
    ;
  }
  cout << *m1;
  Matrix<int> result_matrix = m1->nth_power(power);
  cout << "(" << m1_name << ")^" << power << " =\n" << result_matrix;
  cout << "Do you want to save (" << m1_name << ")^" << power
       << "? (1 = yes / 0 = no)\n";
  int ans;
  cin >> ans;
  if (ans) {
    cout << "Enter the name of the matrix: ";
    string matrix_name;
    cin >> matrix_name;
    memory_map[matrix_name] = result_matrix;
  }
}


// 8
void calculate_det() {
  try {
    string m1_name;
    cout << "Choose matrix: ";
    Matrix<int> *m1 = 0;
    while (!(m1 = choose_matrix_from_map(m1_name))) {
      ;
    }
    cout << *m1;
    int det = m1->det();
    cout << "|" << m1_name << "|" << " = " << det << "\n";
  }
  catch (const std::exception &ex) {
    cerr << ex.what() << "\n";
  }
}


int show_menu() {
  while (true) {
    cout << "==========================================================\n";
    cout << "1. Enter a new matrix.\n"
         << "2. Show an exiting matrix.\n"
         << "3. Add two matrices.\n"
         << "4. Multiply a matrix by a number.\n"
         << "5. Multiply two matrices.\n"
         << "6. Transpose a matrix.\n"
         << "7. Calculate an integer exponent of a matrix.\n"
         << "8. Calculate the determinant of a matrix.\n"
         << "9. Exit the program.\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice > 9 || choice < 1) {
      cerr << "Invalid choice. Try again." << endl;
      continue;
    }
    cout << "==========================================================\n";
    return choice;
  }
}
