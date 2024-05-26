#include "../matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (matrix_null_ptr(A) || matrix_null_ptr(B) ||
      matrix_null_ptr(result) ||
      incorrect_matrix(A->rows, A->columns) ||
      incorrect_matrix(B->rows, B->columns)) {
    return INVALID_MATRIX;
  } else if (nan_or_inf(A) || nan_or_inf(B) || A->columns != B->rows)
    return CALC_ERR;

  Error_codes err_flag = create_matrix(A->rows, B->columns, result);

  if (!err_flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return err_flag;
}