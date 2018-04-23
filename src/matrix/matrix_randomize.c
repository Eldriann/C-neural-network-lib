/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Randomize a matrix between two numbers
*/

/* File created the 11/04/2018 at 13:25:43 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_matrix.h"
#include "nn_miscellanous.h"

static float map_to_range(float value, float min, float max)
{
	return (min + (max - min) * value);
}

int nn_matrix_randomize(nn_matrix_t *mat, float min, float max)
{
	float rand_nb = 0;

	if (max <= min) {
		puts_error("nn_matrix_randomize:Min Max error\n");
		return (84);
	}
	if (mat == NULL || mat->values == NULL) {
		puts_error("nn_matrix_randomize:NULL matrix\n");
		return (84);
	}
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			rand_nb = (float)rand() / (float)RAND_MAX;
			mat->values[row][col] = map_to_range(rand_nb, min, max);
		}
	}
	return (0);
}