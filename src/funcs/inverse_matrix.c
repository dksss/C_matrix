#include "../matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  if (incorrect_matrix(A->rows, A->columns) || matrix_null_ptr(A) ||
      matrix_null_ptr(result))
    return INVALID_MATRIX;
  else if (A->rows != A->columns || nan_or_inf(A))
    return CALC_ERR;

  Error_codes err_flag = OK;
  double det = 0.0;
  determinant(A, &det);

  if (det) {
    matrix_t complements = {0}, transpose = {0};

    calc_complements(A, &complements);
    transpose(&complements, &transpose);
    mult_number(&transpose, 1 / det, result);

    remove_matrix(&complements);
    remove_matrix(&transpose);
  } else
    err_flag = CALC_ERR;

  return err_flag;
}