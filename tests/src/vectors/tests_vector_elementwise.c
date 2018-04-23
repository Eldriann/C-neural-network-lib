/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the elementwise functions
*/

/* File created the 10/04/2018 at 16:46:23 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(nn_vector_add, valid_vectors, .timeout=1)
{
	float array_a[3] = {1.0, 2.5, 0.0};
	float array_b[3] = {-2.0, 2.3, 1.0};
	nn_vector_t *a = create_nn_vector_from_array(array_a, 3);
	nn_vector_t *b = create_nn_vector_from_array(array_b, 3);
	nn_vector_t *c = NULL;

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	c = nn_vector_add(a, b);
	cr_assert(c != NULL);
	for (unsigned int i = 0; i < c->nb_values; i++) {
		cr_assert_eq(c->values[i], a->values[i] + b->values[i]);
	}
	destroy_nn_vector(a);
	destroy_nn_vector(b);
	destroy_nn_vector(c);
}

Test(nn_vector_add, invalid_vectors, .timeout=1)
{
	float array_a[3] = {1.0, 2.5, 0.0};
	float array_b[4] = {-2.0, 2.3, 1.0, 7.1};
	nn_vector_t *a = create_nn_vector_from_array(array_a, 3);
	nn_vector_t *b = create_nn_vector_from_array(array_b, 4);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	cr_assert(nn_vector_add(NULL, NULL) == NULL);
	cr_assert(nn_vector_add(a, NULL) == NULL);
	cr_assert(nn_vector_add(NULL, b) == NULL);
	cr_assert(nn_vector_add(a, b) == NULL);
	destroy_nn_vector(a);
	destroy_nn_vector(b);
}

Test(nn_vector_sub, valid_vectors, .timeout=1)
{
	float array_a[3] = {1.0, 2.5, 0.0};
	float array_b[3] = {-2.0, 2.3, 1.0};
	nn_vector_t *a = create_nn_vector_from_array(array_a, 3);
	nn_vector_t *b = create_nn_vector_from_array(array_b, 3);
	nn_vector_t *c = NULL;

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	c = nn_vector_sub(a, b);
	cr_assert(c != NULL);
	for (unsigned int i = 0; i < c->nb_values; i++) {
		cr_assert_eq(c->values[i], a->values[i] - b->values[i]);
	}
	destroy_nn_vector(a);
	destroy_nn_vector(b);
	destroy_nn_vector(c);
}

Test(nn_vector_sub, invalid_vectors, .timeout=1)
{
	float array_a[3] = {1.0, 2.5, 0.0};
	float array_b[4] = {-2.0, 2.3, 1.0, 7.1};
	nn_vector_t *a = create_nn_vector_from_array(array_a, 3);
	nn_vector_t *b = create_nn_vector_from_array(array_b, 4);

	cr_assert(a != NULL);
	cr_assert(b != NULL);
	cr_assert(nn_vector_sub(NULL, NULL) == NULL);
	cr_assert(nn_vector_sub(a, NULL) == NULL);
	cr_assert(nn_vector_sub(NULL, b) == NULL);
	cr_assert(nn_vector_sub(a, b) == NULL);
	destroy_nn_vector(a);
	destroy_nn_vector(b);
}