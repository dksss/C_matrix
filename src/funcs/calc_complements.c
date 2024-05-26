#include "../matrix.h"

void get_minor(matrix_t *A, matrix_t *minor, int index_i, int index_j) {
  for (int i = 0, i_mnr = 0; i < A->rows; i++) {
    for (int j = 0, j_mnr = 0; j < A->columns; j++) {
      if (i != index_i && j != index_j) {
        minor->matrix[i_mnr][j_mnr] = A->matrix[i][j];
        j_mnr++;

        if (j_mnr == minor->columns) {
          i_mnr++;
          j_mnr = 0;
        }
      }
    }
  }
}

int calc_complements(matrix_t *A, matrix_t *result) {
  if (incorrect_matrix(A->rows, A->columns) || matrix_null_ptr(A) ||
      matrix_null_ptr(result))
    return INVALID_MATRIX;
  else if (A->rows < 2 || A->rows != A->columns || nan_or_inf(A))
    return CALC_ERR;

  Error_codes err_flag = create_matrix(A->rows, A->columns, result);

  if (!err_flag) {
    matrix_t minor = {0};
    create_matrix(A->rows - 1, A->columns - 1, &minor);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        get_minor(A, &minor, i, j);

        double res = 0;
        determinant(&minor, &res);

        if ((i + j) % 2) res *= -1;

        result->matrix[i][j] = res;
      }
    }

    remove_matrix(&minor);
  }

  return err_flag;
}