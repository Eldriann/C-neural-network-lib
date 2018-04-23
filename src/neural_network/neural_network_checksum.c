/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Compute the checksum of the brain
*/

/* File created the 13/04/2018 at 15:33:47 by julian.frabel@epitech.eu */

#include "nn.h"

static unsigned int compute_matrix_checksum(nn_matrix_t *mat)
{
	unsigned int checksum = 0;
	union nn_float_uint_cast_s caster;

	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			caster.float_value =  mat->values[row][col];
			checksum += caster.u_int_value;
		}
	}
	return (checksum);
}

unsigned int compute_checksum(nn_neural_network_t *nn)
{
	unsigned int value = 0;

	value += ((unsigned int)nn->nb_i_node);
	value += ((unsigned int)nn->nb_layer_h);
	value += ((unsigned int)nn->nb_h_node);
	value += ((unsigned int)nn->nb_o_node);
	for (int i = 0; i <= nn->nb_layer_h; i++) {
		value += compute_matrix_checksum(nn->layers[i].bias);
		value += compute_matrix_checksum(nn->layers[i].weights);
	}
	return (~value);
}