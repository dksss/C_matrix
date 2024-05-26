#include "../matrix.h"

int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (incorrect_matrix(A->rows, A->columns) ||
      incorrect_matrix(B->rows, B->columns) || matrix_null_ptr(A) ||
      matrix_null_ptr(B) || matrix_null_ptr(result)) {
    return INVALID_MATRIX;
  } else if (eq_matrix_size(A, B) || nan_or_inf(A) ||
             nan_or_inf(B)) {
    return CALC_ERR;
  }

  Error_codes err_flag = create_matrix(A->rows, A->columns, result);

  if (!err_flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return err_flag;
}