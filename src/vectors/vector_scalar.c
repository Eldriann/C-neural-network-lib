/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Multiply a vector by a given value
*/

/* File created the 10/04/2018 at 15:18:58 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_vectors.h"
#include "nn_miscellanous.h"

nn_vector_t *nn_vector_multiply(nn_vector_t *vector, float multiplicator)
{
	nn_vector_t *result = NULL;

	if (vector == NULL || vector->values == NULL) {
		puts_error("nn_vector_multiply:NULL vector\n");
		return (NULL);
	}
	result = create_empty_nn_vector(vector->nb_values);
	if (result == NULL) {
		puts_error("nn_vector_multiply:Failed to malloc result\n");
		return (NULL);
	}
	for (unsigned int i = 0; i < vector->nb_values; i++) {
		result->values[i] = vector->values[i] * multiplicator;
	}
	return (result);
}

nn_vector_t *nn_vector_divide(nn_vector_t *vector, float divisor)
{
	nn_vector_t *result = NULL;

	if (divisor == 0) {
		puts_error("nn_vector_divide:divisor can not be 0\n");
		return (NULL);
	}
	if (vector == NULL || vector->values == NULL) {
		puts_error("nn_vector_divide:NULL vector\n");
		return (NULL);
	}
	result = create_empty_nn_vector(vector->nb_values);
	if (result == NULL) {
		puts_error("nn_vector_multiply:Failed to malloc result\n");
		return (NULL);
	}
	for (unsigned int i = 0; i < vector->nb_values; i++) {
		result->values[i] = vector->values[i] / divisor;
	}
	return (result);
}