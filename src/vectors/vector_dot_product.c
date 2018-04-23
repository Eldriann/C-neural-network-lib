/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Compute a dot product between two vectors and return the value
*/

/* File created the 10/04/2018 at 16:18:32 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_vectors.h"
#include "nn_miscellanous.h"

float nn_vector_dot_product(nn_vector_t *a, nn_vector_t *b)
{
	float result = 0.0;

	if (a == NULL || b == NULL || a->values == NULL || b->values == NULL) {
		puts_error("nn_vector_dot_product:NULL vector\n");
		return (0.0);
	}
	if (a->nb_values != b->nb_values) {
		puts_error("nn_vector_dot_product:Vectors are not same size\n");
		return (0.0);
	}
	for (unsigned int i = 0; i < a->nb_values; i++) {
		result += (a->values[i] * b->values[i]);
	}
	return (result);
}