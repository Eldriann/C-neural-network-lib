/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Store in a replay memory
*/

/* File created the 17/04/2018 at 17:38:04 by julian.frabel@epitech.eu */

#include <stdlib.h>
#include "nn.h"

void store_in_replay_memory(nn_neural_network_t *nn, nn_replay_memory_t *replay)
{
	static int curr_index = 0;

	if (!replay->new_state || !replay->state) {
		destroy_nn_matrix(replay->state);
		destroy_nn_matrix(replay->new_state);
		return;
	}
	if (curr_index >= REPLAY_MEM_SIZE)
		curr_index = 0;
	destroy_nn_matrix(nn->settings.replay_mem[curr_index].state);
	destroy_nn_matrix(nn->settings.replay_mem[curr_index].new_state);
	nn->settings.replay_mem[curr_index].state = replay->state;
	nn->settings.replay_mem[curr_index].action = replay->action;
	nn->settings.replay_mem[curr_index].is_final = replay->is_final;
	nn->settings.replay_mem[curr_index].new_state = replay->new_state;
	nn->settings.replay_mem[curr_index].reward_got = replay->reward_got;
	curr_index++;
	if (nn->settings.replay_index < curr_index)
		nn->settings.replay_index = curr_index;
}