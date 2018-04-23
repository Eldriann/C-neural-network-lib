/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the feedforward function
*/

/* File created the 11/04/2018 at 18:01:49 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(feed_forward_from_mat, valid_nn_valid_inputs_one_hidden, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
	nn_matrix_t *inputs = create_empty_nn_matrix(2, 1);
	nn_matrix_t *outputs = NULL;

	cr_assert(nn != NULL);
	cr_assert(inputs != NULL);
	outputs = feed_forward_from_mat(nn, inputs);
	cr_assert(outputs != NULL);
	cr_assert_eq(outputs->nb_columns, 1);
	cr_assert_eq(outputs->nb_rows, 1);
	destroy_nn_matrix(inputs);
	destroy_nn_neural_network(nn);
}

Test(feed_forward_from_mat, valid_nn_valid_inputs_many_hidden, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 2, 2, 1);
	nn_matrix_t *inputs = create_empty_nn_matrix(2, 1);
	nn_matrix_t *outputs = NULL;

	cr_assert(nn != NULL);
	cr_assert(inputs != NULL);
	outputs = feed_forward_from_mat(nn, inputs);
	cr_assert(outputs != NULL);
	cr_assert_eq(outputs->nb_columns, 1);
	cr_assert_eq(outputs->nb_rows, 1);
	destroy_nn_matrix(inputs);
	destroy_nn_neural_network(nn);
}

Test(feed_forward_from_mat, invalid_nn_valid_inputs, .timeout=1)
{
	nn_matrix_t *inputs = create_empty_nn_matrix(2, 1);

	cr_assert(inputs != NULL);
	cr_assert(feed_forward_from_mat(NULL, inputs) == NULL);
	destroy_nn_matrix(inputs);
}

Test(feed_forward_from_mat, valid_nn_invalid_inputs, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);

	cr_assert(nn != NULL);
	cr_assert(feed_forward_from_mat(nn, NULL) == NULL);
	destroy_nn_neural_network(nn);
}

Test(feed_forward_from_mat, invalid_nn_invalid_inputs, .timeout=1)
{
	cr_assert(feed_forward_from_mat(NULL, NULL) == NULL);
}

Test(feed_forward, valid_nn_valid_inputs, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
	float inputs[2] = {2.0, 1.0};
	float *outputs = NULL;

	cr_assert(nn != NULL);
	cr_assert(inputs != NULL);
	outputs = feed_forward(nn, inputs);
	cr_assert(outputs != NULL);
	free(outputs);
	destroy_nn_neural_network(nn);
}