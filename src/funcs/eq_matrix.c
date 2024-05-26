#include "../matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  if (matrix_null_ptr(A) || matrix_null_ptr(B) ||
      eq_matrix_size(A, B))
    return FAILURE;

  int err_flag = SUCCESS;

  for (int i = 0; i < A->rows && err_flag == SUCCESS; i++) {
    for (int j = 0; j < A->columns && err_flag == SUCCESS; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY)
        err_flag = FAILURE;
    }
  }

  return err_flag;
}