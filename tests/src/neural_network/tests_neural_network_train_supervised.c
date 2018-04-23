/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Test the train supervised learning functions
*/

/* File created the 12/04/2018 at 18:24:54 by julian.frabel@epitech.eu */

#include <criterion/criterion.h>
#include "nn.h"

Test(train_supervised, valid_arguments_one_hidden, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
	float inputs[2] = {1.0, 2.0};
	float target[2] = {1.0};

	cr_assert(nn != NULL);
	cr_assert(train_supervised(nn, inputs, target) == 0);
	destroy_nn_neural_network(nn);
}

Test(train_supervised, valid_arguments_many_hidden, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 2, 2, 1);
	float inputs[2] = {1.0, 2.0};
	float target[2] = {1.0};

	cr_assert(nn != NULL);
	cr_assert(train_supervised(nn, inputs, target) == 0);
	destroy_nn_neural_network(nn);
}

Test(train_supervised, invalid_arguments, .timeout=1)
{
	nn_neural_network_t *nn = create_neural_network(2, 1, 2, 1);
	float inputs[2] = {1.0, 2.0};
	float target[2] = {1.0};

	cr_assert(nn != NULL);
	cr_assert(train_supervised(NULL, inputs, target) == 84);
	cr_assert(train_supervised(nn, NULL, target) == 84);
	cr_assert(train_supervised(nn, inputs, NULL) == 84);
	cr_assert(train_supervised(NULL, NULL, target) == 84);
	cr_assert(train_supervised(NULL, inputs, NULL) == 84);
	cr_assert(train_supervised(nn, NULL, NULL) == 84);
	cr_assert(train_supervised(NULL, NULL, NULL) == 84);
	destroy_nn_neural_network(nn);
}