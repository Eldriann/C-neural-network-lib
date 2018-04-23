/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Output the max reward of the nn
*/

/* File created the 23/04/2018 at 11:42:37 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

float max_reward(nn_neural_network_t *nn, nn_matrix_t *state, int *index)
{
	float biggest = -100000.0;
	nn_matrix_t *guess = NULL;

	if (nn == NULL || state == NULL)
		return (-84);
	guess = feed_forward_from_mat(nn, state);
	if (guess == NULL)
		return (-84);
	for (int i = 0; i < nn->nb_o_node; i++) {
		if (guess->values[i][0] > biggest && index != NULL)
			*index = i;
		if (guess->values[i][0] > biggest)
			biggest = guess->values[i][0];
	}
	destroy_nn_matrix(guess);
	return (biggest);
}