/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Matrix scalar functions
*/

/* File created the 10/04/2018 at 18:56:47 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_miscellanous.h"

nn_matrix_t *nn_matrix_multiply(nn_matrix_t *matrix, float mul)
{
	nn_matrix_t *result = NULL;

	if (matrix == NULL || matrix->values == NULL) {
		puts_error("nn_matrix_multiply:NULL matrix\n");
		return (NULL);
	}
	result = create_empty_nn_matrix(matrix->nb_rows, matrix->nb_columns);
	if (result == NULL) {
		puts_error("nn_matrix_multiply:Failed to malloc matrix\n");
		return (NULL);
	}
	for (int y = 0; y < result->nb_rows; y++) {
		for (int x = 0; x < result->nb_columns; x++) {
			result->values[y][x] = matrix->values[y][x] * mul;
		}
	}
	return (result);
}

nn_matrix_t *nn_matrix_add(nn_matrix_t *matrix, float to_add)
{
	nn_matrix_t *result = NULL;

	if (matrix == NULL || matrix->values == NULL) {
		puts_error("nn_matrix_multiply:NULL matrix\n");
		return (NULL);
	}
	result = create_empty_nn_matrix(matrix->nb_rows, matrix->nb_columns);
	if (result == NULL) {
		puts_error("nn_matrix_multiply:Failed to malloc matrix\n");
		return (NULL);
	}
	for (int y = 0; y < result->nb_rows; y++) {
		for (int x = 0; x < result->nb_columns; x++) {
			result->values[y][x] = matrix->values[y][x] + to_add;
		}
	}
	return (result);
}

nn_matrix_t *nn_matrix_divide(nn_matrix_t *matrix, float divisor)
{
	nn_matrix_t *result = NULL;

	if (matrix == NULL || matrix->values == NULL) {
		puts_error("nn_matrix_divide:NULL matrix\n");
		return (NULL);
	}
	if (divisor == 0) {
		puts_error("nn_matrix_divide:Divisor can not be 0\n");
		return (NULL);
	}
	result = create_empty_nn_matrix(matrix->nb_rows, matrix->nb_columns);
	if (result == NULL) {
		puts_error("nn_matrix_divide:Failed to malloc matrix\n");
		return (NULL);
	}
	for (int y = 0; y < result->nb_rows; y++) {
		for (int x = 0; x < result->nb_columns; x++) {
			result->values[y][x] = matrix->values[y][x] / divisor;
		}
	}
	return (result);
}