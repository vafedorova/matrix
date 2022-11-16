#include "matrix.h"
#include "menu.h"

int main() {
  while (true) {
    switch (show_menu()) {
    case 1:
      enter_matrix();
      break;
    case 2:
      show_matrix();
      break;
    case 3:
      add_matrices();
      break;
    case 4:
      muptiply_by_number();
      break;
    case 5:
      multiply_two_matrices();
      break;
    case 6:
      transpose_matrix();
      break;
    case 7:
      nth_power_matrix();
      break;
    case 8:
      calculate_det();
      break;
    case 9:
      return 0;
    }
  }
}