/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the matrix core functions
*/

/* File created the 10/04/2018 at 18:13:16 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(create_empty_nn_matrix, valid_row_cols, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(2, 2);

	cr_assert(mat != NULL);
	cr_assert(mat->values != NULL);
	cr_assert_eq(mat->nb_columns, 2);
	cr_assert_eq(mat->nb_rows, 2);
	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			cr_assert_eq(mat->values[row][col], 0.0);
		}
	}
	destroy_nn_matrix(mat);
}

Test(create_empty_nn_matrix, invalid_row_cols, .timeout=1)
{
	cr_assert(create_empty_nn_matrix(0, 0) == NULL);
	cr_assert(create_empty_nn_matrix(2, 0) == NULL);
	cr_assert(create_empty_nn_matrix(0, 2) == NULL);
	cr_assert(create_empty_nn_matrix(-1, 2) == NULL);
	cr_assert(create_empty_nn_matrix(2, -1) == NULL);
}