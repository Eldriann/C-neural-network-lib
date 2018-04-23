/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Core for creating a n dimentional vector
*/

/* File created the 10/04/2018 at 13:12:19 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn_vectors.h"
#include "nn_miscellanous.h"

nn_vector_t *create_empty_nn_vector(int nb_values)
{
	nn_vector_t *new_vector = NULL;

	if (nb_values <= 0) {
		puts_error("create_empty_nn_vector:Invalid param\n");
		return (NULL);
	}
	new_vector = malloc(sizeof(*new_vector));
	if (new_vector == NULL) {
		puts_error("create_empty_nn_vector:malloc failed\n");
		return (NULL);
	}
	new_vector->nb_values = nb_values;
	new_vector->values = malloc(sizeof(*(new_vector->values)) * nb_values);
	if (new_vector->values == NULL) {
		puts_error("create_empty_nn_vector:array malloc failed\n");
		free(new_vector);
		return (NULL);
	}
	for (int i = 0; i < nb_values; i++)
		new_vector->values[i] = 0.0;
	return (new_vector);
}

nn_vector_t *create_nn_vector_from_array(float *array, int nb_values)
{
	nn_vector_t *new_vector = NULL;

	if (array == NULL || nb_values <= 0) {
		puts_error("create_nn_vector_from_array:Invalid param\n");
		return (NULL);
	}
	new_vector = malloc(sizeof(*new_vector));
	if (new_vector == NULL) {
		puts_error("create_nn_vector_from_array:malloc failed\n");
		return (NULL);
	}
	new_vector->nb_values = nb_values;
	new_vector->values = malloc(sizeof(*(new_vector->values)) * nb_values);
	if (new_vector->values == NULL) {
		puts_error("create_nn_vector_from_array:array malloc failed\n");
		free(new_vector);
		return (NULL);
	}
	for (int i = 0; i < nb_values; i++)
		new_vector->values[i] = array[i];
	return (new_vector);
}

void destroy_nn_vector(nn_vector_t *vector)
{
	if (vector == NULL) {
		puts_error("destroy_nn_vector:Invalid param\n");
		return;
	}
	if (vector->values != NULL)
		free(vector->values);
	free(vector);
}