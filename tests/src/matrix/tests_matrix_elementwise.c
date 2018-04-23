/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the elementwise functions
*/

/* File created the 10/04/2018 at 19:58:06 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_add_matrix, valid_matrix, .timeout=1)
{
	float array[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
	nn_matrix_t *a = create_empty_nn_matrix(2, 2);
	nn_matrix_t *b = create_empty_nn_matrix(2, 2);
	nn_matrix_t *res = NULL;

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	for (int y = 0; y < a->nb_rows; y++) {
		for (int x = 0; x < a->nb_columns; x++) {
			a->values[y][x] = array[y][x];
			b->values[y][x] = array[y][x];
		}
	}
	res = nn_matrix_add_matrix(a, b);
	cr_assert(res != NULL);
	for (int y = 0; y < a->nb_rows; y++) {
		for (int x = 0; x < a->nb_columns; x++) {
			cr_assert_eq(res->values[y][x], a->values[y][x] + b->values[y][x]);
		}
	}
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
	destroy_nn_matrix(res);
}

Test(nn_matrix_add_matrix, invalid_matrix, .timeout=1)
{
	nn_matrix_t *a = create_empty_nn_matrix(2, 2);
	nn_matrix_t *b = create_empty_nn_matrix(2, 2);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	cr_assert(nn_matrix_add_matrix(NULL, NULL) == NULL);
	cr_assert(nn_matrix_add_matrix(a, NULL) == NULL);
	cr_assert(nn_matrix_add_matrix(NULL, b) == NULL);
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
}

Test(nn_matrix_schur_product, valid_matrix, .timeout=1)
{
	float array[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
	nn_matrix_t *a = create_empty_nn_matrix(2, 2);
	nn_matrix_t *b = create_empty_nn_matrix(2, 2);
	nn_matrix_t *res = NULL;

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	for (int y = 0; y < a->nb_rows; y++) {
		for (int x = 0; x < a->nb_columns; x++) {
			a->values[y][x] = array[y][x];
			b->values[y][x] = array[y][x];
		}
	}
	res = nn_matrix_schur_product(a, b);
	cr_assert(res != NULL);
	for (int y = 0; y < a->nb_rows; y++) {
		for (int x = 0; x < a->nb_columns; x++) {
			cr_assert_eq(res->values[y][x], a->values[y][x] * b->values[y][x]);
		}
	}
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
	destroy_nn_matrix(res);
}

Test(nn_matrix_schur_product, invalid_matrix, .timeout=1)
{
	nn_matrix_t *a = create_empty_nn_matrix(2, 2);
	nn_matrix_t *b = create_empty_nn_matrix(2, 2);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	cr_assert(nn_matrix_schur_product(NULL, NULL) == NULL);
	cr_assert(nn_matrix_schur_product(a, NULL) == NULL);
	cr_assert(nn_matrix_schur_product(NULL, b) == NULL);
	destroy_nn_matrix(a);
	destroy_nn_matrix(b);
}