/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Train a neural network using reinforcement learning
*/

/* File created the 16/04/2018 at 16:14:34 by julian.frabel@epitech.eu */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "nn.h"

static void fit_network(nn_neural_network_t *nn, \
nn_matrix_t *state, nn_matrix_t *targets)
{
	float inputs[state->nb_rows];
	float outputs[targets->nb_rows];

	for (int i = 0; i < state->nb_rows; i++)
		inputs[i] =  state->values[i][0];
	for (int i = 0; i < targets->nb_rows; i++)
		outputs[i] = targets->values[i][0];
	train_supervised(nn, inputs, outputs);
}

static void replay_experience(nn_neural_network_t *nn)
{
	float target = 0;
	nn_matrix_t *targets = NULL;

	if (nn->settings.training_batch_size > nn->settings.replay_index)
		return;
	for (int i = 0, j = 0; i < nn->settings.training_batch_size; i++) {
		j = rand() % nn->settings.replay_index;
		target = nn->settings.replay_mem[j].reward_got;
		if (!nn->settings.replay_mem[j].is_final)
			target += nn->settings.gamma * max_reward(nn, \
nn->settings.replay_mem[j].new_state, NULL);
		if ((targets = feed_forward_from_mat(nn, \
nn->settings.replay_mem[j].state)) == NULL)
			continue;
		targets->values[nn->settings.replay_mem[j].action][0] = target;
		fit_network(nn, nn->settings.replay_mem[j].state, targets);
		destroy_nn_matrix(targets);
	}
	if (nn->settings.epsilon > nn->settings.epsilon_min)
		nn->settings.epsilon -= nn->settings.epsilon_decay;
}

static int act(nn_neural_network_t *nn, const float *state)
{
	int index = 0;
	nn_matrix_t *state_mat = NULL;

	if (((float)rand() / (float)RAND_MAX) <= nn->settings.epsilon)
		return (rand() % nn->nb_o_node);
	state_mat = create_empty_nn_matrix(nn->nb_i_node, 1);
	if (state_mat == NULL)
		return (rand() % nn->nb_o_node);
	for (int i = 0; i < nn->nb_i_node; i++)
		state_mat->values[i][0] = state[i];
	max_reward(nn, state_mat, &index);
	destroy_nn_matrix(state_mat);
	return (index);
}

static float run_episode(nn_neural_network_t *nn, \
nn_replay_memory_t *(*observer)(const int action_to_take), float state[])
{
	nn_replay_memory_t *replay = NULL;
	int action = 0;
	float score = 0.0;

	for (int i = 0; i < nn->settings.nb_step_before_break; i++) {
		action = act(nn, state);
		replay = observer(action);
		score += replay->reward_got;
		store_in_replay_memory(nn, replay);
		for (int j = 0; j < nn->nb_i_node; j++)
			state[j] = replay->new_state->values[j][0];
		if (replay->is_final) {
			free(replay);
			break;
		}
		free(replay);
	}
	return (score);
}

int train_reinforced(nn_neural_network_t *nn, const float *init_state, \
nn_replay_memory_t *(*observer)(const int action_to_take), void (*reset)())
{
	float state[nn->nb_i_node];
	float episode_score = 0;

	for (unsigned int ep = 0; ep < nn->settings.episodes; ep++) {
		if (NN_DISPLAY_DEBUG_MESSAGES)
			dprintf(2, "[TRAIN]Starting episode [%i/%i]\n", \
ep, nn->settings.episodes);
		for (int i = 0; i < nn->nb_i_node; i++)
			state[i] = init_state[i];
		reset();
		episode_score = run_episode(nn, observer, state);
		if (NN_DISPLAY_DEBUG_MESSAGES)
			dprintf(2, "[TRAIN]End episode [%f]\n", episode_score);
		replay_experience(nn);
	}
	return (0);
}