/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the scalar functions of the matrix
*/

/* File created the 10/04/2018 at 19:01:43 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_multiply, valid_matrix, .timeout=1)
{
	float array[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
	float mul = 2.0;
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);
	nn_matrix_t *res = NULL;

	cr_assert(mat != NULL);
	for (int y = 0; y < mat->nb_rows; y++)
		for (int x = 0; x < mat->nb_columns; x++)
			mat->values[y][x] = array[y][x];
	res = nn_matrix_multiply(mat, mul);
	cr_assert(res != NULL);
	for (int y = 0; y < mat->nb_rows; y++) {
		for (int x = 0; x < mat->nb_columns; x++) {
			cr_assert_eq(res->values[y][x], array[y][x] * mul);
		}
	}
	destroy_nn_matrix(mat);
	destroy_nn_matrix(res);
}

Test(nn_matrix_multiply, invalid_matrix, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(nn_matrix_multiply(NULL, 2.0) == NULL);
	if (mat != NULL) {
		mat->values = NULL;
		cr_assert(nn_matrix_multiply(mat, 2.0) == NULL);
		destroy_nn_matrix(mat);
	}
}

Test(nn_matrix_add, valid_matrix, .timeout=1)
{
	float array[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
	float to_add = 2.0;
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);
	nn_matrix_t *res = NULL;

	cr_assert(mat != NULL);
	for (int y = 0; y < mat->nb_rows; y++)
		for (int x = 0; x < mat->nb_columns; x++)
			mat->values[y][x] = array[y][x];
	res = nn_matrix_add(mat, to_add);
	cr_assert(res != NULL);
	for (int y = 0; y < mat->nb_rows; y++) {
		for (int x = 0; x < mat->nb_columns; x++) {
			cr_assert_eq(res->values[y][x], array[y][x] + to_add);
		}
	}
	destroy_nn_matrix(mat);
	destroy_nn_matrix(res);
}

Test(nn_matrix_add, invalid_matrix, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(nn_matrix_add(NULL, 2.0) == NULL);
	if (mat != NULL) {
		mat->values = NULL;
		cr_assert(nn_matrix_add(mat, 2.0) == NULL);
		destroy_nn_matrix(mat);
	}
}

Test(nn_matrix_divide, valid_matrix, .timeout=1)
{
	float array[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
	float divisor = 2.0;
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);
	nn_matrix_t *res = NULL;

	cr_assert(mat != NULL);
	for (int y = 0; y < mat->nb_rows; y++)
		for (int x = 0; x < mat->nb_columns; x++)
			mat->values[y][x] = array[y][x];
	res = nn_matrix_divide(mat, divisor);
	cr_assert(res != NULL);
	for (int y = 0; y < res->nb_rows; y++) {
		for (int x = 0; x < res->nb_columns; x++) {
			cr_assert_eq(res->values[y][x], array[y][x] / divisor);
		}
	}
	destroy_nn_matrix(mat);
	destroy_nn_matrix(res);
}

Test(nn_matrix_divide, invalid_matrix, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(nn_matrix_divide(NULL, 2.0) == NULL);
	if (mat != NULL) {
		mat->values = NULL;
		cr_assert(nn_matrix_divide(mat, 2.0) == NULL);
		destroy_nn_matrix(mat);
	}
}

Test(nn_matrix_divide, invalid_divisor, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(nn_matrix_divide(mat, 0) == NULL);
	destroy_nn_matrix(mat);
}