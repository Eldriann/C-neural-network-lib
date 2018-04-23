/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Save a neural network to a file
*/

/* File created the 13/04/2018 at 12:10:16 by julian.frabel@epitech.eu */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nn.h"

static char *get_curr_time_str(void)
{
	time_t curr_time;
	struct tm *tmp = NULL;
	char *result = NULL;

	curr_time = time(NULL);
	tmp = localtime(&curr_time);
	if (tmp == NULL) {
		puts_error("get_curr_time_str:localtime\n");
		return (NULL);
	}
	result = malloc(sizeof(*result) * 26);
	if (result == NULL) {
		puts_error("get_curr_time_str:malloc\n");
		return (NULL);
	}
	if (strftime(result, 26, "%d_%m_%y_%H_%M_%S.nnbrain", tmp) == 0) {
		puts_error("get_curr_time_str:strftime\n");
		free(result);
		return (NULL);
	}
	return (result);
}

static char *get_brain_name(const char *name)
{
	char *name_brain = NULL;

	if (name == NULL) {
		name_brain = get_curr_time_str();
		if (name_brain == NULL)
			return (NULL);
	} else {
		name_brain = malloc(sizeof(*name_brain) * (strlen(name) + 9));
		if (name_brain == NULL)
			return (NULL);
		strcpy(name_brain, name);
		strcat(name_brain, ".nnbrain");
	}
	return (name_brain);
}

static int write_matrix(nn_matrix_t *mat, int fd)
{
	int written = 0;

	for (int row = 0; row < mat->nb_rows; row++)
		for (int col = 0; col < mat->nb_columns; col++)
			written += write(fd, &(mat->values[row][col]), \
sizeof(mat->values[row][col]));
	return (written);
}

static int write_neural_network(nn_neural_network_t *nn, int fd)
{
	unsigned int byte_written = 0;
	unsigned int checksum = compute_checksum(nn);
	int settings[5] = {0x7D4E4E7B, nn->nb_i_node, nn->nb_layer_h, \
nn->nb_h_node, nn->nb_o_node};
	unsigned int expected_written = 24;

	if (nn == NULL || fd == -1)
		return (84);
	byte_written += write(fd, settings, sizeof(*settings) * 5);
	for (int i = 0; i <= nn->nb_layer_h; i++) {
		byte_written += write_matrix(nn->layers[i].bias, fd);
		byte_written += write_matrix(nn->layers[i].weights, fd);
	}
	byte_written += write(fd, &checksum, sizeof(checksum));
	expected_written += (4 * (settings[3] * (1 + settings[1])));
	expected_written += (4 * ((settings[3] * (1 + settings[3])) * \
(settings[2] - 1)));
	expected_written += (4 * (settings[4] * (1 + settings[3])));
	if (byte_written == expected_written)
		return (0);
	return (84);
}

int nn_neural_network_save(nn_neural_network_t *nn, const char *name)
{
	char *name_brain = get_brain_name(name);
	int fd = -1;

	if (name_brain == NULL)
		return (84);
	fd = open(name_brain, O_CREAT | O_TRUNC | O_RDWR, BRAIN_FILE_PERM);
	if (fd == -1) {
		puts_error("nn_neural_network_save:failed open\n");
		free(name_brain);
		return (84);
	}
	if (write_neural_network(nn, fd) == 84) {
		puts_error("nn_neural_network_save:write_neural_network\n");
		close(fd);
		free(name_brain);
		return (84);
	}
	close(fd);
	free(name_brain);
	return (0);
}