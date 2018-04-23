/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Perform the sigmoid function
*/

/* File created the 11/04/2018 at 15:58:48 by julian.frabel@epitech.eu */

#include <math.h>

float nn_sigmoid(float nb)
{
	return (1.0 / (1 + exp(-nb)));
}

float nn_dsigmoid(float nb)
{
	return (nn_sigmoid(nb) * (1 - nn_sigmoid(nb)));
}

float nn_dysigmoid(float nb)
{
	return (nb * (1 - nb));
}