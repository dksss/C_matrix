#include "../matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  if (incorrect_matrix(rows, columns) || matrix_null_ptr(result))
    return INVALID_MATRIX;

  Error_codes err_flag = OK;

  result->matrix = (double **)calloc(rows, sizeof(double *));

  if (!result->matrix) {
    err_flag = INVALID_MATRIX;
  } else {
    for (int i = 0; i < rows && !err_flag; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));

      if (!result->matrix[i]) {
        err_flag = INVALID_MATRIX;
      }
    }
    result->rows = rows;
    result->columns = columns;
  }

  return err_flag;
}