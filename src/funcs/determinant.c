#include "../matrix.h"

void swap_rows(matrix_t *A, double *tmp, int index, int swap_index) {
  A->matrix[swap_index] = A->matrix[index];
  A->matrix[index] = tmp;
}

void calculate_determinant(matrix_t *copy, double *result) {
  int det_sign = 1;
  *result = 1.0;
  int first_value = 0;
  int zero_flag = 1;
  double *tmp_row = NULL;

  for (int i = 0; i < copy->rows - 1 && *result; i++) {
    for (first_value = i, zero_flag = 1; first_value < copy->rows;
         first_value++) {
      if (copy->matrix[first_value][i]) {
        zero_flag = 0;
        tmp_row = copy->matrix[first_value];
        break;
      }
    }
    if (copy->matrix[i][i] == 0 && tmp_row) {
      swap_rows(copy, tmp_row, i, first_value);
      det_sign *= -1;
    }
    if (zero_flag) {
      *result = 0.0;
    } else {
      for (int j = i + 1; j < copy->rows; j++) {
        double elem = copy->matrix[j][i] / copy->matrix[i][i];
        for (int k = i; k < copy->columns; k++) {
          copy->matrix[j][k] -= copy->matrix[i][k] * elem;
        }
      }
    }
  }

  if (*result) {
    *result *= det_sign;
    for (int i = 0; i < copy->rows; i++) *result *= copy->matrix[i][i];
  }
}

int determinant(matrix_t *A, double *result) {
  if (incorrect_matrix(A->rows, A->columns) || matrix_null_ptr(A) ||
      !result) {
    return INVALID_MATRIX;
  } else if (A->rows != A->columns || nan_or_inf(A))
    return CALC_ERR;

  matrix_t copy = {0};
  Error_codes err_flag = create_copy(A, &copy);

  if (!err_flag) {
    calculate_determinant(&copy, result);

    remove_matrix(&copy);
  }

  return err_flag;
}