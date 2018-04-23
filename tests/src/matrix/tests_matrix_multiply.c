/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the matrix multiplication function
*/

/* File created the 11/04/2018 at 10:02:48 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_multiply_matrix, valid_matrices, .timeout=1)
{
	float array_a[2][3] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
	float array_b[3][2] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
	nn_matrix_t *a = create_empty_nn_matrix(2, 3);
	nn_matrix_t *b = create_empty_nn_matrix(3, 2);
	nn_matrix_t *res = NULL;
	float dot_product = 0;

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	for (int y = 0; y < a->nb_rows; y++)
		for (int x = 0; x < a->nb_columns; x++)
			a->values[y][x] = array_a[y][x];
	for (int y = 0; y < b->nb_rows; y++)
		for (int x = 0; x < b->nb_columns; x++)
			b->values[y][x] = array_b[y][x];
	res = nn_matrix_multiply_matrix(a, b);
	cr_assert(res != NULL);
	for (int y = 0; y < a->nb_rows; y++) {
		for (int x = 0; x < b->nb_columns; x++) {
			dot_product = array_a[y][0] * array_b[0][x] + array_a[y][1] * array_b[1][x] + array_a[y][2] * array_b[2][x];
			cr_assert_eq(res->values[y][x], dot_product);
		}
	}
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
	destroy_nn_matrix(res);
}

Test(nn_matrix_multiply_matrix, invalid_matrix, .timeout=1)
{
	nn_matrix_t *a = create_empty_nn_matrix(2, 3);
	nn_matrix_t *b = create_empty_nn_matrix(10, 7);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	cr_assert(nn_matrix_multiply_matrix(NULL, NULL) == NULL);
	cr_assert(nn_matrix_multiply_matrix(a, NULL) == NULL);
	cr_assert(nn_matrix_multiply_matrix(NULL, b) == NULL);
	cr_assert(nn_matrix_multiply_matrix(a, b) == NULL);
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
}