#include "../matrix.h"

int mult_number(matrix_t *A, double number, matrix_t *result) {
  if (incorrect_matrix(A->rows, A->columns) || matrix_null_ptr(A) ||
      matrix_null_ptr(result)) {
    return INVALID_MATRIX;
  } else if (nan_or_inf(A) || isinf(number) || isnan(number))
    return CALC_ERR;

  Error_codes err_flag = create_matrix(A->rows, A->columns, result);

  if (!err_flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return err_flag;
}