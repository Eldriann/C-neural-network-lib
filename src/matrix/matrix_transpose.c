/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Transpose a matrix (row to columns and columns to row)
*/

/* File created the 11/04/2018 at 13:03:06 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_vectors.h"
#include "nn_miscellanous.h"

nn_matrix_t *nn_matrix_transpose(nn_matrix_t *mat)
{
	nn_matrix_t *res = NULL;

	if (mat == NULL || mat->values == NULL) {
		puts_error("nn_matrix_transpose:NULL matrix\n");
		return (NULL);
	}
	res = create_empty_nn_matrix(mat->nb_columns, mat->nb_rows);
	if (res == NULL) {
		puts_error("nn_matrix_transpose:Failed to malloc new matrix\n");
		return (NULL);
	}
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			res->values[col][row] = mat->values[row][col];
		}
	}
	return (res);
}