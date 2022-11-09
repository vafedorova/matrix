#ifndef _MENU_H_
#define _MENU_H_
#include <string>
#include "matrix.h"

void enter_matrix();
Matrix *choose_matrix_from_map(std::string &matrix_name);
void show_matrix(); 
void add_matrices();
void muptiply_by_number(); 
void multiply_two_matrices();
void transpose_matrix(); 
void nth_power_matrix(); 
int show_menu(); 
#endif