/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** randomize a matrix given a range
*/

/* File created the 11/04/2018 at 13:37:34 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_randomize, valid_input_range_0_1, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(3, 3);
	float min = 0;
	float max = 1;

	cr_assert(mat != NULL);
	cr_assert(nn_matrix_randomize(mat, min, max) == 0);
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			cr_assert(mat->values[row][col] >= min);
			cr_assert(mat->values[row][col] <= max);
		}
	}
	destroy_nn_matrix(mat);
}

Test(nn_matrix_randomize, valid_input_range_5_11, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(3, 3);
	float min = 5;
	float max = 11;

	cr_assert(mat != NULL);
	cr_assert(nn_matrix_randomize(mat, min, max) == 0);
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			cr_assert(mat->values[row][col] >= min);
			cr_assert(mat->values[row][col] <= max);
		}
	}
	destroy_nn_matrix(mat);
}

Test(nn_matrix_randomize, invalid_matrix, .timeout=1)
{
	cr_assert(nn_matrix_randomize(NULL, 0, 1) == 84);
}

Test(nn_matrix_randomize, invalid_min_max, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(3, 3);

	cr_assert(nn_matrix_randomize(mat, 0, 0) == 84);
	cr_assert(nn_matrix_randomize(mat, 1, 0) == 84);
	destroy_nn_matrix(mat);
}

Test(nn_matrix_randomize, invalid_min_max_invalid_matrix, .timeout=1)
{
	cr_assert(nn_matrix_randomize(NULL, 0, 0) == 84);
	cr_assert(nn_matrix_randomize(NULL, 1, 0) == 84);
}