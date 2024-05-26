#ifndef MATRIX_H
#define MATRIX_H

#include <math.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define ACCURACY 1e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum Error_codes {
  OK = 0,
  INVALID_MATRIX = 1,
  CALC_ERR = 2
} Error_codes;

int create_matrix(int rows, int columns, matrix_t *result);
void remove_matrix(matrix_t *A);
int eq_matrix(matrix_t *A, matrix_t *B);
int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int mult_number(matrix_t *A, double number, matrix_t *result);
int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int transpose(matrix_t *A, matrix_t *result);
int calc_complements(matrix_t *A, matrix_t *result);
int determinant(matrix_t *A, double *result);
int inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции
int incorrect_matrix(int rows, int columns);
int matrix_null_ptr(matrix_t *A);
int eq_matrix_size(matrix_t *A, matrix_t *B);
int nan_or_inf(matrix_t *A);
int create_copy(matrix_t *A, matrix_t *result);

#endif