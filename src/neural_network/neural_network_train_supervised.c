/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Train a neural network using supervised learning
*/

/* File created the 12/04/2018 at 10:39:20 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

static nn_matrix_t *calculate_output_error(float *guess, const float *expected,\
int nb_values)
{
	nn_matrix_t *err_mat = create_empty_nn_matrix(nb_values, 1);

	if (err_mat == NULL) {
		puts_error("calculate_output_error:Failed to malloc matrix\n");
		return (NULL);
	}
	if (guess == NULL || expected == NULL) {
		puts_error("calculate_output_error:NULL param\n");
		destroy_nn_matrix(err_mat);
		return (NULL);
	}
	for (int i = 0; i < nb_values; i++) {
		err_mat->values[i][0] = expected[i] - guess[i];
	}
	return (err_mat);
}

int train_supervised(nn_neural_network_t *nn, const float *inputs, \
const float *targets)
{
	float *guess = NULL;
	nn_matrix_t *errors = NULL;
	int return_val = 0;

	if (nn == NULL || inputs == NULL || targets == NULL) {
		puts_error("train_supervised:NULL param\n");
		return (84);
	}
	guess = feed_forward(nn, inputs);
	errors = calculate_output_error(guess, targets, nn->nb_o_node);
	if (guess == NULL || errors == NULL) {
		puts_error("train_supervised:Failed to get guess\n");
		return_val = 84;
	}
	if (backpropagate(nn, errors) == 84)
		return_val = 84;
	free(guess);
	destroy_nn_matrix(errors);
	return (return_val);
}