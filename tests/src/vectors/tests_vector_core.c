/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the vector core file functions
*/

/* File created the 10/04/2018 at 14:55:23 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(create_empty_nn_vector, valid_vector_size, .timeout=1)
{
	nn_vector_t *new_vector = create_empty_nn_vector(3);

	cr_assert(new_vector != NULL);
	cr_assert_eq(new_vector->nb_values, 3);
	cr_assert(new_vector->values != NULL);
	for (unsigned int i = 0; i < new_vector->nb_values; i++)
		cr_assert_eq(new_vector->values[i], 0.0);
	destroy_nn_vector(new_vector);
}

Test(create_empty_nn_vector, invalid_vector_size, .timeout=1)
{
	cr_assert(create_empty_nn_vector(0) == NULL);
	cr_assert(create_empty_nn_vector(-2) == NULL);
}

Test(create_nn_vector_from_array, valid_array_valid_size, .timeout=5)
{
	float array[3] = {3.0, 6.3, 1.1};
	nn_vector_t *new_vector = create_nn_vector_from_array(array, 3);

	cr_assert(new_vector != NULL);
	cr_assert_eq(new_vector->nb_values, 3);
	cr_assert(new_vector->values != NULL);
	for (unsigned int i = 0; i < new_vector->nb_values; i++)
		cr_assert_eq(new_vector->values[i], array[i]);
	destroy_nn_vector(new_vector);
}

Test(create_nn_vector_from_array, invalid_array_valid_size, .timeout=5)
{
	cr_assert(create_nn_vector_from_array(NULL, 3) == NULL);
}

Test(create_nn_vector_from_array, valid_array_invalid_size, .timeout=5)
{
	float array[3] = {3.0, 6.3, 1.1};

	cr_assert(create_nn_vector_from_array(array, 0) == NULL);
	cr_assert(create_nn_vector_from_array(array, -5) == NULL);
}

Test(create_nn_vector_from_array, invalid_array_invalid_size, .timeout=5)
{
	cr_assert(create_nn_vector_from_array(NULL, 0) == NULL);
	cr_assert(create_nn_vector_from_array(NULL, -5) == NULL);
}