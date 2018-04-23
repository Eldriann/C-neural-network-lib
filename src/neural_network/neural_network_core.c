/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Core to create a neural network
*/

/* File created the 11/04/2018 at 16:06:30 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

static void initialize_layer(nn_neural_layer_t *layer, int nb_i, int nb_h, \
int first)
{
	layer->bias = create_empty_nn_matrix(nb_h, 1);
	layer->weights = create_empty_nn_matrix(nb_h, (first) ? nb_i : nb_h);
	layer->outputs = NULL;
	layer->activation = &nn_sigmoid;
	layer->derivative = &nn_dysigmoid;
	nn_matrix_randomize(layer->bias, -1, 1);
	nn_matrix_randomize(layer->weights, -1, 1);
}

static int initialize_nn(nn_neural_network_t *nn, int nb_i, int nb_h, int nb_o)
{
	nn->nb_i_node = nb_i;
	nn->nb_h_node = nb_h;
	nn->nb_o_node = nb_o;
	nn->layers = malloc(sizeof(*(nn->layers)) * (nn->nb_layer_h + 1));
	if (nn->layers == NULL)
		return (84);
	for (int i = 0; i < nn->nb_layer_h; i++) {
		initialize_layer(&nn->layers[i], nb_i, nb_h, !i);
	}
	nn->layers[nn->nb_layer_h].bias = create_empty_nn_matrix(nb_o, 1);
	nn->layers[nn->nb_layer_h].weights = create_empty_nn_matrix(nb_o, nb_h);
	nn->layers[nn->nb_layer_h].outputs = NULL;
	nn->layers[nn->nb_layer_h].activation = &nn_sigmoid;
	nn->layers[nn->nb_layer_h].derivative = &nn_dysigmoid;
	nn_matrix_randomize(nn->layers[nn->nb_layer_h].bias, -1, 1);
	nn_matrix_randomize(nn->layers[nn->nb_layer_h].weights, -1, 1);
	return (0);
}

static int initialize_reinforcement_settings(nn_neural_network_t *nn)
{
	nn->settings.episodes = NN_DEFAULT_NB_EPISODE;
	nn->settings.epsilon = NN_DEFAULT_EXPLORE_PROB;
	nn->settings.epsilon_decay = NN_DEFAULT_EXPLORE_DECAY;
	nn->settings.epsilon_min = NN_DEFAULT_MIN_EXPLORE_PROB;
	nn->settings.gamma = NN_DEFAULT_FUTUR_REWARD_DISCOUNT;
	nn->settings.nb_step_before_break = NN_DEFAULT_STEP_BEFORE_BREAK;
	nn->settings.training_batch_size = NN_DEFAULT_TRAINING_BATCH_SIZE;
	nn->settings.replay_index = 0;
	for (int i = 0; i < REPLAY_MEM_SIZE; i++) {
		nn->settings.replay_mem[i].action = 0;
		nn->settings.replay_mem[i].new_state = NULL;
		nn->settings.replay_mem[i].state = NULL;
		nn->settings.replay_mem[i].reward_got = 0;
	}
	return (0);
}

nn_neural_network_t *create_neural_network(int nb_input, int nb_hidden_layer, \
int nb_hidden_nodes, int nb_output)
{
	nn_neural_network_t *new_nn = NULL;

	if (nb_input <= 0 || nb_hidden_layer <= 0 || \
nb_hidden_nodes <= 0 || nb_output <= 0)
		return (NULL);
	new_nn = malloc(sizeof(*new_nn));
	if (new_nn == NULL) {
		puts_error("create_neural_network:Failed to malloc\n");
		return (NULL);
	}
	new_nn->nb_layer_h = nb_hidden_layer;
	new_nn->learning_rate = NN_DEFAULT_LEARNING_RATE;
	initialize_reinforcement_settings(new_nn);
	new_nn->initial_input = NULL;
	if (initialize_nn(new_nn, nb_input, nb_hidden_nodes, nb_output)) {
		destroy_nn_neural_network(new_nn);
		return (NULL);
	}
	return (new_nn);
}

void destroy_nn_neural_network(nn_neural_network_t *nn)
{
	if (nn == NULL) {
		puts_error("destroy_nn_neural_network:NULL nn\n");
		return;
	}
	for (int i = 0; i <= nn->nb_layer_h; i++) {
		destroy_nn_matrix(nn->layers[i].bias);
		destroy_nn_matrix(nn->layers[i].weights);
		destroy_nn_matrix(nn->layers[i].outputs);
	}
	for (int i = 0; i < nn->settings.replay_index; i++) {
		destroy_nn_matrix(nn->settings.replay_mem[i].new_state);
		destroy_nn_matrix(nn->settings.replay_mem[i].state);
	}
	destroy_nn_matrix(nn->initial_input);
	free(nn->layers);
	free(nn);
}