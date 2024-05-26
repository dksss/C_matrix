#include "../matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  if (incorrect_matrix(A->rows, A->columns) || matrix_null_ptr(A) ||
      matrix_null_ptr(result))
    return INVALID_MATRIX;

  Error_codes err_flag = create_matrix(A->columns, A->rows, result);

  if (!err_flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return err_flag;
}