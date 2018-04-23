/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Create and destroy matrixs
*/

/* File created the 10/04/2018 at 17:51:33 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_miscellanous.h"

static int malloc_inert_matrix(nn_matrix_t *mat, int rows, int cols)
{
	int i = 0;

	mat->values = malloc(sizeof(*(mat->values)) * rows);
	if (mat->values == NULL)
		return (84);
	for (i = 0; i < rows; i++) {
		mat->values[i] = malloc(sizeof(*(mat->values[i])) * cols);
		if (mat->values[i] == NULL)
			break;
		for (int x = 0; x < cols; x++)
			mat->values[i][x] = 0.0;
	}
	if (i == rows)
		return (0);
	for (i = 0; mat->values[i] != NULL; i++)
		free(mat->values[i]);
	return (84);
}

nn_matrix_t *create_empty_nn_matrix(int rows, int columns)
{
	nn_matrix_t *new_matrix = NULL;

	if (rows <= 0 || columns <= 0) {
		puts_error("create_empty_nn_matrix:Invalid parameter\n");
		return (NULL);
	}
	new_matrix = malloc(sizeof(*new_matrix));
	if (new_matrix == NULL)
		return (NULL);
	new_matrix->nb_rows = rows;
	new_matrix->nb_columns = columns;
	if (malloc_inert_matrix(new_matrix, rows, columns)) {
		puts_error("create_empty_nn_matrix:Malloc failed\n");
		free(new_matrix);
		return (NULL);
	}
	return (new_matrix);
}

void destroy_nn_matrix(nn_matrix_t *matrix)
{
	if (matrix == NULL) {
		return;
	}
	if (matrix->values == NULL) {
		free(matrix);
		return;
	}
	for (int row = 0; row < matrix->nb_rows; row++) {
		if (matrix->values[row])
			free(matrix->values[row]);
	}
	free(matrix->values);
	free(matrix);
}