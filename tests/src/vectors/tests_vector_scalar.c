/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the multiply vector function
*/

/* File created the 10/04/2018 at 15:23:06 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_vector_multiply, valid_vector, .timeout=1)
{
	float array[5] = {3.0, 1.0, -2.3, 6.66, 0.0};
	float mul = 2.0;
	nn_vector_t *vector = create_nn_vector_from_array(array, 5);
	nn_vector_t *result = NULL;

	cr_assert(vector != NULL);
	result = nn_vector_multiply(vector, mul);
	cr_assert(result != NULL);
	for (unsigned int i = 0; i < vector->nb_values; i++) {
		cr_assert_eq(result->values[i], array[i] * mul);
	}
	destroy_nn_vector(vector);
	destroy_nn_vector(result);
}

Test(nn_vector_multiply, invalid_vector, .timeout=1)
{
	nn_vector_t *vector = create_empty_nn_vector(3);

	cr_assert(nn_vector_multiply(NULL, 2.0) == NULL);
	if (vector != NULL) {
		free(vector->values);
		vector->values = NULL;
		cr_assert(nn_vector_multiply(vector, 2.0) == NULL);
		destroy_nn_vector(vector);
	}
}

Test(nn_vector_divide, valid_vector, .timeout=1)
{
	float array[5] = {3.0, 1.0, -2.3, 6.66, 0.0};
	float divisor = 2.0;
	nn_vector_t *vector = create_nn_vector_from_array(array, 5);
	nn_vector_t *result = NULL;

	cr_assert(vector != NULL);
	result = nn_vector_divide(vector, divisor);
	cr_assert(result != NULL);
	for (unsigned int i = 0; i < vector->nb_values; i++) {
		cr_assert_eq(result->values[i], array[i] / divisor);
	}
	destroy_nn_vector(vector);
	destroy_nn_vector(result);
}

Test(nn_vector_divide, invalid_vector, .timeout=1)
{
	nn_vector_t *vector = create_empty_nn_vector(3);

	cr_assert(nn_vector_divide(NULL, 2.0) == NULL);
	if (vector != NULL) {
		free(vector->values);
		vector->values = NULL;
		cr_assert(nn_vector_divide(vector, 2.0) == NULL);
		destroy_nn_vector(vector);
	}
}

Test(nn_vector_divide, invalid_divisor, .timeout=1)
{
	nn_vector_t *vector = create_empty_nn_vector(3);

	cr_assert(nn_vector_divide(vector, 0) == NULL);
	destroy_nn_vector(vector);
}