/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Elementwise matrix operation (same size matrix)
*/

/* File created the 10/04/2018 at 19:51:14 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_miscellanous.h"

nn_matrix_t *nn_matrix_add_matrix(nn_matrix_t *a, nn_matrix_t *b)
{
	nn_matrix_t *res = NULL;

	if (a == NULL || a->values == NULL || b == NULL || b->values == NULL) {
		puts_error("nn_matrix_add_matrix:NULL matrix\n");
		return (NULL);
	}
	if (a->nb_rows != b->nb_rows || a->nb_columns != b->nb_columns) {
		puts_error("nn_matrix_add_matrix:Matrix are not same size\n");
		return (NULL);
	}
	res = create_empty_nn_matrix(a->nb_rows, a->nb_columns);
	if (res == NULL) {
		puts_error("nn_matrix_add_matrix:Failed to malloc matrix\n");
		return (NULL);
	}
	for (int y = 0; y < res->nb_rows; y++)
		for (int x = 0; x < res->nb_columns; x++)
			res->values[y][x] = a->values[y][x] + b->values[y][x];
	return (res);
}

nn_matrix_t *nn_matrix_schur_product(nn_matrix_t *a, nn_matrix_t *b)
{
	nn_matrix_t *res = NULL;

	if (a == NULL || a->values == NULL || b == NULL || b->values == NULL) {
		puts_error("nn_matrix_schur_product:NULL matrix\n");
		return (NULL);
	}
	if (a->nb_rows != b->nb_rows || a->nb_columns != b->nb_columns) {
		puts_error("nn_matrix_schur_product:Matrix not same size\n");
		return (NULL);
	}
	res = create_empty_nn_matrix(a->nb_rows, a->nb_columns);
	if (res == NULL) {
		puts_error("nn_matrix_schur_product:Failed to malloc matrix\n");
		return (NULL);
	}
	for (int y = 0; y < res->nb_rows; y++)
		for (int x = 0; x < res->nb_columns; x++)
			res->values[y][x] = a->values[y][x] * b->values[y][x];
	return (res);
}