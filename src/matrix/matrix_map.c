/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Apply a function to each element of the matrix
*/

/* File created the 12/04/2018 at 14:19:15 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

int nn_matrix_map(nn_matrix_t *mat, float (*func)(float))
{
	if (mat == NULL || func == NULL) {
		puts_error("nn_matrix_map:NULL param\n");
		return (84);
	}
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			mat->values[row][col] = func(mat->values[row][col]);
		}
	}
	return (0);
}