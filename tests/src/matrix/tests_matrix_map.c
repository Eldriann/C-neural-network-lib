/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the matrix map function
*/

/* File created the 12/04/2018 at 14:24:56 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

static float minus_one(float val)
{
	return (val - 1);
}

Test(nn_matrix_map, valid_args, .timeout=1)
{
	float array[3][3] = {{1.9, 2.0, 3.2}, {4.0, 5.3, 6.0}, {7.0, 8.0, 0.0}};
	nn_matrix_t *mat = create_empty_nn_matrix(3, 3);

	cr_assert(mat != NULL);
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			mat->values[row][col] = array[row][col];
		}
	}
	cr_assert(nn_matrix_map(mat, &minus_one) == 0);
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			cr_assert(mat->values[row][col] == array[row][col] - 1);
		}
	}
	destroy_nn_matrix(mat);
}

Test(nn_matrix_map, invalid_args, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(mat != NULL);
	cr_assert(nn_matrix_map(NULL, NULL) == 84);
	cr_assert(nn_matrix_map(NULL, &minus_one) == 84);
	cr_assert(nn_matrix_map(mat, NULL) == 84);
	destroy_nn_matrix(mat);
}