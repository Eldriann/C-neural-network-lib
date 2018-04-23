/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Backproagate an error
*/

/* File created the 12/04/2018 at 15:22:00 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

static nn_matrix_t *get_new_error(nn_matrix_t *weights, nn_matrix_t *errors)
{
	nn_matrix_t *transposed_weights = nn_matrix_transpose(weights);
	nn_matrix_t *new_errors = NULL;

	if (transposed_weights == NULL) {
		puts_error("get_new_error:Transpose failed\n");
		return (NULL);
	}
	new_errors = nn_matrix_multiply_matrix(transposed_weights, errors);
	destroy_nn_matrix(transposed_weights);
	return (new_errors);
}

static int adjust_weights(nn_neural_layer_t *layer, nn_matrix_t *errors, \
nn_matrix_t *io_data[2], float learning_rate)
{
	nn_matrix_t *gradient_errors = NULL;
	nn_matrix_t *gradient = NULL;
	nn_matrix_t *input_transposed = nn_matrix_transpose(io_data[0]);
	nn_matrix_t *delta_w = NULL;

	nn_matrix_map(io_data[1], layer->derivative);
	gradient_errors = nn_matrix_schur_product(errors, io_data[1]);
	gradient = nn_matrix_multiply(gradient_errors, learning_rate);
	delta_w = nn_matrix_multiply_matrix(gradient, input_transposed);
	for (int i = 0; delta_w != NULL && i < layer->weights->nb_rows; i++)
		for (int j = 0; j < layer->weights->nb_columns; j++)
			(layer->weights->values[i][j]) += delta_w->values[i][j];
	destroy_nn_matrix(gradient_errors);
	destroy_nn_matrix(gradient);
	destroy_nn_matrix(input_transposed);
	destroy_nn_matrix(delta_w);
	return ((delta_w == NULL) ? 84 : 0);
}

static int adjust_bias(nn_matrix_t *bias, nn_matrix_t *errors, \
nn_matrix_t *outputs, float learning_rate)
{
	nn_matrix_t *gradient_errors = NULL;
	nn_matrix_t *gradient = NULL;

	gradient_errors = nn_matrix_schur_product(errors, outputs);
	gradient = nn_matrix_multiply(gradient_errors, learning_rate);
	for (int row = 0; gradient != NULL && row < bias->nb_rows; row++)
		for (int col = 0; col < bias->nb_columns; col++)
			(bias->values[row][col]) += gradient->values[row][col];
	destroy_nn_matrix(gradient_errors);
	destroy_nn_matrix(gradient);
	return ((gradient == NULL) ? 84 : 0);
}

static int process_layer(nn_neural_layer_t *layer, nn_matrix_t *input, \
nn_matrix_t *err, float lr)
{
	nn_matrix_t *io_data[2] = {input, layer->outputs};

	if (err == NULL) {
		puts_error("process_layer:NULL error\n");
		return (84);
	}
	if (adjust_weights(layer, err, io_data, lr)) {
		puts_error("process_layer:adjust_weights returned error\n");
		return (84);
	}
	if (adjust_bias(layer->bias, err, layer->outputs, lr)) {
		puts_error("process_layer:adjust_bias returned error\n");
		return (84);
	}
	return (0);
}

int backpropagate(nn_neural_network_t *nn, nn_matrix_t *err_o)
{
	int r_err = 0;
	nn_matrix_t *old_err = err_o;
	nn_matrix_t *new_err = err_o;
	float lr = nn->learning_rate;

	if (nn == NULL || err_o == NULL)
		return (84);
	for (int i = nn->nb_layer_h; i > 0; i--) {
		new_err = get_new_error(nn->layers[i].weights, old_err);
		r_err += process_layer(&(nn->layers[i]), \
nn->layers[i - 1].outputs, old_err, lr);
		destroy_nn_matrix((old_err != err_o) ? old_err : NULL);
		old_err = new_err;
	}
	r_err += process_layer(nn->layers, nn->initial_input, old_err, lr);
	destroy_nn_matrix(old_err);
	return ((r_err != 0) ? 84 : 0);
}