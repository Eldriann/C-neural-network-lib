/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Miscellanous functions
*/

/* File created the 10/04/2018 at 13:31:41 by julian.frabel@epitech.eu */

#ifndef __NN_MISCELLANOUS__H_
	#define __NN_MISCELLANOUS__H_

	#include "nn_matrix.h"
	#include "nn_neural_network.h"

	/***
	** \brief Display an error message on the standart error output
	** @param error the error message to be written
	**
	** Display the error message on the standart error output.
	** Only display if NN_DISPLAY_ERROR_MESSAGES is true.
	** Return the number of written characters.
	*/
	int puts_error(char const *error);

	/***
	** \brief Display an debug message on the standart error output
	** @param debug the debug message to be written
	**
	** Display the debug message on the standart error output.
	** Only display if NN_DISPLAY_DEBUG_MESSAGES is true.
	** Return the number of written characters.
	*/
	int puts_debug(char const *debug);

	/***
	** \brief Perform the sigmoid function
	**
	** Return the value passed into the sigmoid function.
	*/
	float nn_sigmoid(float nb);
	/***
	** \brief Perform the derivative sigmoid function
	**
	** Return the value passed into the function.
	*/
	float nn_dsigmoid(float nb);
	/***
	** \brief Perform the dsigmoid function on an already sigmoid nb
	**
	** Used to compute the gradient.
	** Return the value passed into the function.
	*/
	float nn_dysigmoid(float nb);
	/***
	** \brief Perform the tanh function
	**
	** Return the value passed into the function.
	*/
	float nn_tanh(float nb);
	/***
	** \brief Perform the dtanh function on an already tanh nb
	**
	** Used to compute the gradient.
	** Return the value passed into the function.
	*/
	float nn_dtanh(float nb);
	/***
	** \brief Perform a linear function
	**
	** Return the value passed into the function.
	*/
	float nn_linear(float nb);
	/***
	** \brief Perform a linear function
	**
	** Used to compute the gradient.
	** Return the value passed into the function.
	*/
	float nn_dlinear(float nb);

	/***
	** \brief return the max reward
	** @param nn the neural network
	** @param state the given state
	** @param index a pointer to the max index
	**
	** If index != NULL set the index of the max value.
	** Return the maximum value of the nn.
	*/
	float max_reward(nn_neural_network_t *nn, \
nn_matrix_t *state, int *index);

#endif /* !__NN_MISCELLANOUS__H_ */