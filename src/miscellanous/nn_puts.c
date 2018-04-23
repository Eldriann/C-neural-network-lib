/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** puts strs on output
*/

/* File created the 10/04/2018 at 13:28:29 by julian.frabel@epitech.eu */

#include <unistd.h>
#include <string.h>
#include "nn_settings.h"

int puts_error(char const *error)
{
	if (!NN_DISPLAY_ERROR_MESSAGES)
		return (0);
	if (error == NULL) {
		return (puts_error("Error message is NULL!\n"));
	}
	return (write(2, "[ERROR]: ", 9) + write(2, error, strlen(error)));
}

int puts_debug(char const *debug)
{
	if (!NN_DISPLAY_DEBUG_MESSAGES)
		return (0);
	if (debug == NULL) {
		return (puts_error("Debug message is NULL!\n"));
	}
	return (write(2, "[DEBUG]: ", 9) + write(2, debug, strlen(debug)));
}