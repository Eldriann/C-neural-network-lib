/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Create a neural_network from file
*/

/* File created the 13/04/2018 at 17:59:38 by julian.frabel@epitech.eu */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "nn.h"

static nn_neural_network_t *create_nn_from_param(int fd)
{
	int nb_i = 0;
	int nb_layer_h = 0;
	int nb_h = 0;
	int nb_o = 0;

	if (read(fd, &nb_i, sizeof(nb_i)) != sizeof(nb_i))
		return (NULL);
	if (read(fd, &nb_layer_h, sizeof(nb_layer_h)) != sizeof(nb_layer_h))
		return (NULL);
	if (read(fd, &nb_h, sizeof(nb_h)) != sizeof(nb_h))
		return (NULL);
	if (read(fd, &nb_o, sizeof(nb_o)) != sizeof(nb_o))
		return (NULL);
	return (create_neural_network(nb_i, nb_layer_h, nb_h, nb_o));
}

static int read_matrix(nn_matrix_t *mat, int fd)
{
	int expected_read = 0;
	int byte_read = 0;

	for (int row = 0; row < mat->nb_rows; row++) {
		for (int col = 0; col < mat->nb_columns; col++) {
			byte_read += read(fd, &(mat->values[row][col]), \
sizeof(mat->values[row][col]));
			expected_read += sizeof(mat->values[row][col]);
		}
	}
	if (expected_read == byte_read)
		return (0);
	puts_error("read_matrix:Error while reading matrix\n");
	return (84);
}

static nn_neural_network_t *read_nn(int fd)
{
	nn_neural_network_t *nn = NULL;
	unsigned int magic_nb = 0;
	int error = 0;

	if (read(fd, &magic_nb, sizeof(magic_nb)) != sizeof(magic_nb))
		return (NULL);
	if (magic_nb != 0x7D4E4E7B) {
		puts_error("read_nn:File is not an nnbrain!\n");
		return (NULL);
	}
	nn = create_nn_from_param(fd);
	if (nn == NULL)
		return (NULL);
	for (int i = 0; i <= nn->nb_layer_h; i++) {
		error += read_matrix(nn->layers[i].bias, fd);
		error += read_matrix(nn->layers[i].weights, fd);
	}
	if (error != 0)
		destroy_nn_neural_network(nn);
	return ((error != 0) ? NULL : nn);
}

nn_neural_network_t *create_neural_network_from_file(const char *file_name)
{
	int fd = -1;
	nn_neural_network_t *nn = NULL;
	unsigned int checksum = 0;

	if (file_name == NULL)
		return (NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	nn = read_nn(fd);
	if ((read(fd, &checksum, sizeof(checksum)) != sizeof(checksum)) || \
(compute_checksum(nn) != checksum)) {
		puts_error("create_neural_network_from_file:Corrupted file\n");
		destroy_nn_neural_network(nn);
		close (fd);
		return (NULL);
	}
	close (fd);
	return (nn);
}