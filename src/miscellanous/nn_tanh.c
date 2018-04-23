/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Hyperbolic tangent function
*/

/* File created the 20/04/2018 at 07:37:37 by julian.frabel@epitech.eu */

#include <math.h>

float nn_tanh(float nb)
{
	return ((1 - exp(-2 * nb) / (1 + exp(-2 * nb))));
}

float nn_dtanh(float nb)
{
	return (1 - nb);
}