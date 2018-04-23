/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the clone function of the matrix
*/

/* File created the 16/04/2018 at 16:23:43 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_clone, valid_matrix, .timeout=1)
{
	nn_matrix_t *mat = create_empty_nn_matrix(3, 4);
	nn_matrix_t *new_mat = NULL;

	cr_assert(mat != NULL);
	nn_matrix_randomize(mat, -1, 1);
	new_mat = nn_matrix_clone(mat);
	cr_assert(new_mat != NULL);
	for (int row = 0; row < new_mat->nb_rows; row++)
		for (int col = 0; col < new_mat->nb_columns; col++)
			cr_assert(new_mat->values[row][col] == mat->values[row][col]);
	destroy_nn_matrix(mat);
	destroy_nn_matrix(new_mat);
}

Test(nn_matrix_clone, invalid_mat, .timeout=1)
{
	cr_assert(nn_matrix_clone(NULL) == NULL);
}