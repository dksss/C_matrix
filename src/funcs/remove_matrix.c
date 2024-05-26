#include "../matrix.h"

void remove_matrix(matrix_t *A) {
  if (A->matrix && !incorrect_matrix(A->rows, A->columns)) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}