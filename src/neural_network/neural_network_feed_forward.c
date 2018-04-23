/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Function that process inputs in the neural network and return the outputs
*/

/* File created the 11/04/2018 at 17:19:35 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

static nn_matrix_t *feed_layer(nn_matrix_t *weights, nn_matrix_t *bias, \
nn_matrix_t *inputs, float (*activation)(float))
{
	nn_matrix_t *weighted_mat = NULL;
	nn_matrix_t *result = NULL;

	weighted_mat = nn_matrix_multiply_matrix(weights, inputs);
	result = nn_matrix_add_matrix(weighted_mat, bias);
	destroy_nn_matrix(weighted_mat);
	if (result == NULL)
		return (NULL);
	nn_matrix_map(result, activation);
	return (result);
}

nn_matrix_t *feed_forward_from_mat(nn_neural_network_t *nn, nn_matrix_t *inputs)
{
	nn_matrix_t *last_outputs = nn_matrix_clone(inputs);

	if (nn == NULL || last_outputs == NULL || nn->layers == NULL) {
		puts_error("feed_forward:NULL Param\n");
		return (NULL);
	}
	destroy_nn_matrix(nn->initial_input);
	nn->initial_input = last_outputs;
	for (int i = 0; i <= nn->nb_layer_h; i++) {
		last_outputs = feed_layer(nn->layers[i].weights, \
nn->layers[i].bias, last_outputs, nn->layers[i].activation);
		destroy_nn_matrix(nn->layers[i].outputs);
		nn->layers[i].outputs = last_outputs;
	}
	return (nn_matrix_clone(last_outputs));
}

float *feed_forward(nn_neural_network_t *nn, const float *inputs)
{
	nn_matrix_t *inputs_mat = create_empty_nn_matrix(nn->nb_i_node, 1);
	nn_matrix_t *output_mat = NULL;
	float *outputs = malloc(sizeof(*outputs) * nn->nb_o_node);

	if (inputs_mat == NULL || outputs == NULL) {
		destroy_nn_matrix(inputs_mat);
		free(outputs);
		return (NULL);
	}
	for (int i = 0; i < nn->nb_i_node; i++)
		inputs_mat->values[i][0] = inputs[i];
	output_mat = feed_forward_from_mat(nn, inputs_mat);
	if (output_mat == NULL) {
		free(outputs);
		return (NULL);
	}
	for (int i = 0; i < output_mat->nb_rows; i++)
		outputs[i] = output_mat->values[i][0];
	destroy_nn_matrix(inputs_mat);
	destroy_nn_matrix(output_mat);
	return (outputs);
}