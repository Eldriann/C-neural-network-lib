/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** cpy a matrix
*/

/* File created the 16/04/2018 at 16:19:25 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"

nn_matrix_t *nn_matrix_clone(const nn_matrix_t *mat)
{
	nn_matrix_t *new_mat = NULL;

	if (mat == NULL)
		return (NULL);
	new_mat = create_empty_nn_matrix(mat->nb_rows, mat->nb_columns);
	if (new_mat == NULL)
		return (NULL);
	for (int row = 0; row < new_mat->nb_rows; row++)
		for (int col = 0; col < new_mat->nb_columns; col++)
			new_mat->values[row][col] = mat->values[row][col];
	return (new_mat);
}