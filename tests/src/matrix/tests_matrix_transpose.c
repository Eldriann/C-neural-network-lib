/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the transpose function
*/

/* File created the 11/04/2018 at 13:05:48 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_matrix_transpose, valid_matrix, .timeout=1)
{
	float array[2][3] = {{1.2, 2.3, 3.0}, {0.4, 5.2, 6.11}};
	nn_matrix_t *mat = create_empty_nn_matrix(2, 3);
	nn_matrix_t *res = NULL;

	cr_assert(mat != NULL);
	for (int row = 0; row < mat->nb_rows; row++)
		for (int col = 0; col < mat->nb_columns; col++)
			mat->values[row][col] = array[row][col];
	res = nn_matrix_transpose(mat);
	cr_assert(res != NULL);
	cr_assert_eq(res->nb_columns, 2);
	cr_assert_eq(res->nb_rows, 3);
	for (int row = 0; row < res->nb_rows; row++)
		for (int col = 0; col < res->nb_columns; col++)
			cr_assert_eq(res->values[row][col], array[col][row]);
}

Test(nn_matrix_transpose, invalid_matrix, .timeout=1)
{
	cr_assert(nn_matrix_transpose(NULL) == NULL);
}