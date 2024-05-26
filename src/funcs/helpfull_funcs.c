#include "../matrix.h"

int incorrect_matrix(int rows, int columns) {
  return (rows < 1 || columns < 1);
}

int matrix_null_ptr(matrix_t *A) { return (A == NULL); }

int eq_matrix_size(matrix_t *A, matrix_t *B) {
  return (A->rows != B->rows || A->columns != B->columns);
}

int nan_or_inf(matrix_t *A) {
  Error_codes err_flag = OK;

  for (int i = 0; i < A->rows && err_flag == OK; i++) {
    for (int j = 0; j < A->columns && err_flag == OK; j++) {
      if (isnan(A->matrix[i][j]) || isinf(A->matrix[i][j])) err_flag = CALC_ERR;
    }
  }
  return err_flag;
}

int create_copy(matrix_t *A, matrix_t *result) {
  Error_codes err_flag = create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j];
    }
  }
  return err_flag;
}