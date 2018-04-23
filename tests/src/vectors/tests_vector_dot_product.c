/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the vector dot product function
*/

/* File created the 10/04/2018 at 16:23:33 by julian.frabel@epitech.eu */

#include <math.h>
#include <criterion/criterion.h>
#include "nn.h"

Test(nn_vector_dot_product, valid_vectors, .timeout=1)
{
	float array_a[5] = {1.0, 2.3, 4.5, 6.7, -1.9};
	float array_b[5] = {4.0, 3.2, -6.9, 0.0, 2.0};
	float result = 0;
	nn_vector_t *a = create_nn_vector_from_array(array_a, 5);
	nn_vector_t *b = create_nn_vector_from_array(array_b, 5);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	result = roundf(nn_vector_dot_product(a, b) *  1000) / 1000;
	cr_assert_eq(result, roundf(-23.490 * 1000) / 1000);
}