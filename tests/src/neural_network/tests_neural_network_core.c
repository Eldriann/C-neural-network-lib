/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the core nn functions
*/

/* File created the 11/04/2018 at 16:35:10 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(create_neural_network, valid_inputs_one_hidden, .timeout=1)
{
	int i_nb = 2;
	int h_nb = 3;
	int o_nb = 1;
	int h_layer_nb = 1;
	nn_neural_network_t *nn = create_neural_network(i_nb, h_layer_nb, h_nb, o_nb);

	cr_assert(nn != NULL);
	cr_assert_eq(nn->nb_i_node, i_nb);
	cr_assert_eq(nn->nb_h_node, h_nb);
	cr_assert_eq(nn->nb_o_node, o_nb);
	cr_assert(nn->nb_layer_h == h_layer_nb);
	cr_assert(nn->initial_input == NULL);
	cr_assert_float_eq(nn->learning_rate, NN_DEFAULT_LEARNING_RATE, 0.01);
	cr_assert(nn->layers != NULL);
	cr_assert(nn->layers[0].outputs == NULL);
	cr_assert(nn->layers[0].weights != NULL);
	cr_assert(nn->layers[0].bias != NULL);
	cr_assert(nn->layers[0].bias->nb_columns == 1);
	cr_assert(nn->layers[0].bias->nb_rows == h_nb);
	cr_assert(nn->layers[0].weights->nb_columns == i_nb);
	cr_assert(nn->layers[0].weights->nb_rows == h_nb);
	for (int i = 1; i < h_layer_nb; i++) {
		cr_assert(nn->layers[i].outputs == NULL);
		cr_assert(nn->layers[i].weights != NULL);
		cr_assert(nn->layers[i].bias != NULL);
		cr_assert(nn->layers[i].bias->nb_columns == 1);
		cr_assert(nn->layers[i].bias->nb_rows == h_nb);
		cr_assert(nn->layers[i].weights->nb_columns == h_nb);
		cr_assert(nn->layers[i].weights->nb_rows == h_nb);
	}
	cr_assert(nn->layers[h_layer_nb].outputs == NULL);
	cr_assert(nn->layers[h_layer_nb].weights != NULL);
	cr_assert(nn->layers[h_layer_nb].bias != NULL);
	cr_assert(nn->layers[h_layer_nb].bias->nb_columns == 1);
	cr_assert(nn->layers[h_layer_nb].bias->nb_rows == o_nb);
	cr_assert(nn->layers[h_layer_nb].weights->nb_columns == h_nb);
	cr_assert(nn->layers[h_layer_nb].weights->nb_rows == o_nb);
	destroy_nn_neural_network(nn);
}

Test(create_neural_network, valid_inputs_many_hidden, .timeout=1)
{
	int i_nb = 2;
	int h_nb = 3;
	int o_nb = 1;
	int h_layer_nb = 3;
	nn_neural_network_t *nn = create_neural_network(i_nb, h_layer_nb, h_nb,  o_nb);

	cr_assert(nn != NULL);
	cr_assert_eq(nn->nb_i_node, i_nb);
	cr_assert_eq(nn->nb_h_node, h_nb);
	cr_assert_eq(nn->nb_o_node, o_nb);
	cr_assert(nn->nb_layer_h == h_layer_nb);
	cr_assert(nn->initial_input == NULL);
	cr_assert_float_eq(nn->learning_rate, NN_DEFAULT_LEARNING_RATE, 0.01);
	cr_assert(nn->layers != NULL);
	cr_assert(nn->layers[0].outputs == NULL);
	cr_assert(nn->layers[0].weights != NULL);
	cr_assert(nn->layers[0].bias != NULL);
	cr_assert(nn->layers[0].bias->nb_columns == 1);
	cr_assert(nn->layers[0].bias->nb_rows == h_nb);
	cr_assert(nn->layers[0].weights->nb_columns == i_nb);
	cr_assert(nn->layers[0].weights->nb_rows == h_nb);
	for (int i = 1; i < h_layer_nb; i++) {
		cr_assert(nn->layers[i].outputs == NULL);
		cr_assert(nn->layers[i].weights != NULL);
		cr_assert(nn->layers[i].bias != NULL);
		cr_assert(nn->layers[i].bias->nb_columns == 1);
		cr_assert(nn->layers[i].bias->nb_rows == h_nb);
		cr_assert(nn->layers[i].weights->nb_columns == h_nb);
		cr_assert(nn->layers[i].weights->nb_rows == h_nb);
	}
	cr_assert(nn->layers[h_layer_nb].outputs == NULL);
	cr_assert(nn->layers[h_layer_nb].weights != NULL);
	cr_assert(nn->layers[h_layer_nb].bias != NULL);
	cr_assert(nn->layers[h_layer_nb].bias->nb_columns == 1);
	cr_assert(nn->layers[h_layer_nb].bias->nb_rows == o_nb);
	cr_assert(nn->layers[h_layer_nb].weights->nb_columns == h_nb);
	cr_assert(nn->layers[h_layer_nb].weights->nb_rows == o_nb);
	destroy_nn_neural_network(nn);
}

Test(create_neural_network, invalid_inputs, .timeout=1)
{
	cr_assert(create_neural_network(0, 0, 0, 0) == NULL);
	cr_assert(create_neural_network(1, 0, 0, 0) == NULL);
	cr_assert(create_neural_network(0, 1, 0, 0) == NULL);
	cr_assert(create_neural_network(0, 0, 0, 1) == NULL);
	cr_assert(create_neural_network(0, 1, 0, 1) == NULL);
	cr_assert(create_neural_network(1, 0, 0, 1) == NULL);
	cr_assert(create_neural_network(1, 1, 0, 0) == NULL);
	cr_assert(create_neural_network(-1, -1, 0, -1) == NULL);
	cr_assert(create_neural_network(1, -1, 0, -1) == NULL);
	cr_assert(create_neural_network(-1, 1, 0, -1) == NULL);
	cr_assert(create_neural_network(-1, -1, 0, 1) == NULL);
	cr_assert(create_neural_network(-1, 1, 0, 1) == NULL);
	cr_assert(create_neural_network(1, -1, 0, 1) == NULL);
	cr_assert(create_neural_network(1, 1, 0, -1) == NULL);
	cr_assert(create_neural_network(0, 0, 1, 0) == NULL);
	cr_assert(create_neural_network(1, 0, 1, 0) == NULL);
	cr_assert(create_neural_network(0, 1, 1, 0) == NULL);
	cr_assert(create_neural_network(0, 0, 1, 1) == NULL);
	cr_assert(create_neural_network(0, 1, 1, 1) == NULL);
	cr_assert(create_neural_network(1, 0, 1, 1) == NULL);
	cr_assert(create_neural_network(1, 1, 1, 0) == NULL);
	cr_assert(create_neural_network(-1, -1, 1, -1) == NULL);
	cr_assert(create_neural_network(1, -1, 1, -1) == NULL);
	cr_assert(create_neural_network(-1, 1, 1, -1) == NULL);
	cr_assert(create_neural_network(-1, -1, 1, 1) == NULL);
	cr_assert(create_neural_network(-1, 1, 1, 1) == NULL);
	cr_assert(create_neural_network(1, -1, 1, 1) == NULL);
	cr_assert(create_neural_network(1, 1, 1, -1) == NULL);
	cr_assert(create_neural_network(0, 0, -1, 0) == NULL);
	cr_assert(create_neural_network(1, 0, -1, 0) == NULL);
	cr_assert(create_neural_network(0, 1, -1, 0) == NULL);
	cr_assert(create_neural_network(0, 0, -1, 1) == NULL);
	cr_assert(create_neural_network(0, 1, -1, 1) == NULL);
	cr_assert(create_neural_network(1, 0, -1, 1) == NULL);
	cr_assert(create_neural_network(1, 1, -1, 0) == NULL);
	cr_assert(create_neural_network(-1, -1, -1, -1) == NULL);
	cr_assert(create_neural_network(1, -1, -1, -1) == NULL);
	cr_assert(create_neural_network(-1, 1, -1, -1) == NULL);
	cr_assert(create_neural_network(-1, -1, -1, 1) == NULL);
	cr_assert(create_neural_network(-1, 1, -1, 1) == NULL);
	cr_assert(create_neural_network(1, -1, -1, 1) == NULL);
	cr_assert(create_neural_network(1, 1, -1, -1) == NULL);
}