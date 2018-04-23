/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Neural Network component header
*/

/* File created the 11/04/2018 at 13:59:04 by julian.frabel@epitech.eu */

/**
** \file nn_neural_network.h
** \brief Header declaring neural network functions
**
** All neural network related stuff is in this header file
*/

#ifndef __NN_NEURAL_NETWORK__H_
	#define __NN_NEURAL_NETWORK__H_

	#include <stdbool.h>
	#include "nn_settings.h"
	#include "nn_matrix.h"

	typedef struct nn_neural_network_s nn_neural_network_t;
	typedef struct nn_neural_layer_s nn_neural_layer_t;
	typedef struct nn_replay_memory_s nn_replay_memory_t;
	typedef struct nn_reinforcement_settings_s nn_reinforcement_settings_t;

	#define BRAIN_FILE_PERM S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

	/**
	** \union nn_float_uint_cast_s
	** \brief Union used by the checksum to cast float to uint
	*/
	union nn_float_uint_cast_s {
		unsigned int u_int_value;
		float float_value;
	};

	/**
	** \struct nn_replay_memory_s
	** \brief Structure representing an action taken
	*/
	struct nn_replay_memory_s {
		nn_matrix_t *state; /**< State before the action */
		int action; /**< Action taken */
		float reward_got; /**< Reward got by taking this action */
		nn_matrix_t *new_state; /**< State after the action */
		bool is_final; /**< Is the new state a final state */
	};

	/**
	** \struct nn_reinforcement_settings_s
	** \brief Structure representing the reinforcement settings of a nn
	*/
	struct nn_reinforcement_settings_s {
		unsigned int episodes; /**< Number of simulations to run */
		float gamma; /**< Discount rate for expected futur reward */
		float epsilon; /**< Exploration rate */
		float epsilon_decay; /**< Decrease of the exploration rate */
		float epsilon_min; /**< Minimal value of epsilon */
		int nb_step_before_break; /**< Number of states before \
episode is aborted */
		nn_replay_memory_t replay_mem[REPLAY_MEM_SIZE];
/**< Replay memory */
		int replay_index; /**< Number of replay in the replay mem */
		int training_batch_size; /**< Size of a training batch */
	};

	/**
	** \struct nn_neural_layer_s
	** \brief Structure representing a layer of a neural network
	*/
	struct nn_neural_layer_s {
		float (*activation)(float); /**< Activation func of the layer */
		float (*derivative)(float); /**< Derivative func of the layer */
		nn_matrix_t *weights; /**< Weights between last and this */
		nn_matrix_t *bias; /**< Bias on this layer */
		nn_matrix_t *outputs;/**< Outputs of this layer (learning use)*/
	};

	/**
	** \struct nn_neural_network_s
	** \brief Structure representing a neural network
	*/
	struct nn_neural_network_s {
		float learning_rate; /**< Learning rate of the nn */
		nn_reinforcement_settings_t settings;
		/**< Settings for reinforcement learning*/
		int nb_i_node; /**< Number of input nodes */
		int nb_h_node; /**< Number of hiden nodes */
		int nb_o_node; /**< Number of output nodes */
		int nb_layer_h; /**< Number of hidden layers */
		nn_neural_layer_t *layers; /**< Thinking layers array */
		nn_matrix_t *initial_input;
		/**< Initial input used in the nn (used for learning) */
	};

	/**
	** \brief Create a new neural network
	** @param nb_input the number of input nodes
	** @param nb_hidden_layer the number of hidden layers
	** @param nb_hidden_nodes the number of hidden nodes
	** @param nb_output the number of output nodes
	**
	** Create a new neural network with the number of requested nodes.
	** Generally input are the number of inputs you are gonna need.
	** Output are gonna be the number of outputs expected.
	** \return NULL if an error occured, the new neural network otherwise.
	*/
	nn_neural_network_t *create_neural_network(int nb_input, \
int nb_hidden_layer, int nb_hidden_nodes, int nb_output);
	/**
	** \brief Create a new neural network
	** @param file_name path to the nnbrain
	**
	** Create a new neural network from a nnbrain file.
	** \return NULL if an error occured, the new neural network otherwise.
	*/
	nn_neural_network_t *create_neural_network_from_file(const char \
*file_name);
	/**
	** \brief Destroy a neural network
	** @param nn the neural network to destroy
	**
	** Destroy a neural network
	*/
	void destroy_nn_neural_network(nn_neural_network_t *nn);

	/**
	** \brief Parse inputs through the neural network
	** @param nn the neural network to parse through
	** @param inputs the inputs as a matrix
	**
	** Parse inputs through the neural network.
	** \return NULL in case of errors, the outputs as matrix otherwise.
	*/
	nn_matrix_t *feed_forward_from_mat(nn_neural_network_t *nn, \
nn_matrix_t *inputs);
	/**
	** \brief Parse inputs through the neural network
	** @param nn the neural network to parse through
	** @param inputs the inputs as a float array
	**
	** Parse inputs through the neural network.
	** Warning: will expect inputs to be the size of the input layer!
	** Warning: will expect nn to be not NULL!
	** If inputs are not the same size as input layer will segfault.
	** You will need to free the output array when not needed anymore.
	** \return NULL in case of errors, the outputs as float array otherwise.
	*/
	float *feed_forward(nn_neural_network_t *nn, const float *inputs);

	/**
	** \brief train a neural network using supervised learning
	** @param nn the neural network to train
	** @param inputs the inputs to train on
	** @param targets the expected outputs
	**
	** Will train a neural network by giving inputs and expected outputs.
	** Warning: Will assume inputs have the length of nn->nb_input_nodes.
	** Warning: Will assume outputs have the length of nn->nb_outputs_nodes.
	** \return 84 if the learning failed, 0 otherwise.
	*/
	int train_supervised(nn_neural_network_t *nn, const float *inputs, \
const float *targets);
	/**
	** \brief train a neural network using reinforcement learning
	** @param nn the neural network to train
	** @param init_state the initial state
	** @param observer function that serve as observer
	** @param reset function that reset the environement
	**
	** Function that will train with reinforcement learning a network.
	** The observer should return a replay memory of the full step.
	** Warning init_state should be nn->nb_inputs size.
	** \return 84 in case of an error 0 otherwise.
	*/
	int train_reinforced(nn_neural_network_t *nn, const float *init_state, \
nn_replay_memory_t *(*observer)(const int action_to_take), void (*reset)());
	/**
	** \brief Store a step in the replay memory.
	** Used internally.
	*/
	void store_in_replay_memory(nn_neural_network_t *nn, \
nn_replay_memory_t *replay);
	/**
	** \brief Backproagate an error through the network adjusting the data
	** @param nn the neural network to adjust
	** @param errors_o the errors got at the end of the network
	**
	** Backproagate an error through the network adjusting the weights/bias.
	** \return 84 if the learning failed, 0 otherwise.
	*/
	int backpropagate(nn_neural_network_t *nn, nn_matrix_t *errors_o);

	/**
	** \brief Compute the checksum of a neural network.
	** @param nn the neural network
	**
	** Function used for saving a neural network and prevent corruption.
	** \return the checksum as an unsigned int.
	*/
	unsigned int compute_checksum(nn_neural_network_t *nn);
	/**
	** \brief save a nn state to a .nnbrain file
	** @param nn the neural network to save
	** @param name [OPTIONAL] the name of the generated file.
	**
	** Will save a nn to a given file.
	** If name is NULL the file will be named from current time.
	** \return 84 in case of an error 0 otherwise.
	*/
	int nn_neural_network_save(nn_neural_network_t *nn, const char *name);

#endif /* !__NN_NEURAL_NETWORK__H_ */