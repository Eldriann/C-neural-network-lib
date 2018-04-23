/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Matrix multiplication
*/

/* File created the 11/04/2018 at 10:01:06 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_vectors.h"
#include "nn_miscellanous.h"

static void fill_vector_from_matrix(nn_matrix_t *from, \
nn_vector_t *vec, int row, int col)
{
	if (row != -1) {
		for (int i = 0; i < from->nb_columns; i++)
			vec->values[i] = from->values[row][i];
	} else if (col != -1) {
		for (int i = 0; i < from->nb_rows; i++)
			vec->values[i] = from->values[i][col];
	}
}

static int fill_matrix_result(nn_matrix_t *a, nn_matrix_t *b, nn_matrix_t *res)
{
	nn_vector_t *v_a = create_empty_nn_vector(a->nb_columns);
	nn_vector_t *v_b = create_empty_nn_vector(b->nb_rows);

	if (v_a == NULL || v_b == NULL) {
		destroy_nn_vector(v_a);
		destroy_nn_vector(v_b);
		return (84);
	}
	for (int row = 0; row < res->nb_rows; row++) {
		fill_vector_from_matrix(a, v_a, row, -1);
		for (int col = 0; col < res->nb_columns; col++) {
			fill_vector_from_matrix(b, v_b, -1, col);
			res->values[row][col] = nn_vector_dot_product(v_a, v_b);
		}
	}
	destroy_nn_vector(v_a);
	destroy_nn_vector(v_b);
	return (0);
}

nn_matrix_t *nn_matrix_multiply_matrix(nn_matrix_t *a, nn_matrix_t *b)
{
	nn_matrix_t *res = NULL;

	if (a == NULL || a->values == NULL || b == NULL || b->values == NULL) {
		puts_error("nn_matrix_multiply_matrix:NULL matrix\n");
		return (NULL);
	}
	if (a->nb_columns != b->nb_rows) {
		puts_error("nn_matrix_multiply_matrix:Matrix A cols!=B rows\n");
		return (NULL);
	}
	res = create_empty_nn_matrix(a->nb_rows, b->nb_columns);
	if (res == NULL) {
		puts_error("nn_matrix_multiply_matrix:Malloc failed\n");
		return (NULL);
	}
	if (fill_matrix_result(a, b, res)) {
		puts_error("nn_matrix_multiply_matrix:Vector calc failed\n");
		destroy_nn_matrix(res);
		return (NULL);
	}
	return (res);
}