/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Calc elementwise vectors
*/

/* File created the 10/04/2018 at 16:39:38 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_vectors.h"
#include "nn_miscellanous.h"

nn_vector_t *nn_vector_add(nn_vector_t *a, nn_vector_t *b)
{
	nn_vector_t *c = NULL;

	if (a == NULL || b == NULL || a->values == NULL || b->values == NULL) {
		puts_error("nn_vector_add:NULL vector\n");
		return (NULL);
	}
	if (a->nb_values != b->nb_values) {
		puts_error("nn_vector_add:Vectors are not same size\n");
		return (NULL);
	}
	c = create_empty_nn_vector(a->nb_values);
	if (c == NULL) {
		puts_error("nn_vector_add:Failed to create new vector\n");
		return (NULL);
	}
	for (unsigned int i = 0; i < c->nb_values; i++) {
		c->values[i] = a->values[i] + b->values[i];
	}
	return (c);
}

nn_vector_t *nn_vector_sub(nn_vector_t *a, nn_vector_t *b)
{
	nn_vector_t *c = NULL;

	if (a == NULL || b == NULL || a->values == NULL || b->values == NULL) {
		puts_error("nn_vector_sub:NULL vector\n");
		return (NULL);
	}
	if (a->nb_values != b->nb_values) {
		puts_error("nn_vector_sub:Vectors are not same size\n");
		return (NULL);
	}
	c = create_empty_nn_vector(a->nb_values);
	if (c == NULL) {
		puts_error("nn_vector_sub:Failed to create new vector\n");
		return (NULL);
	}
	for (unsigned int i = 0; i < c->nb_values; i++) {
		c->values[i] = a->values[i] - b->values[i];
	}
	return (c);
}