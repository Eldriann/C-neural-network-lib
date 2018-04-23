/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Settings header
*/

/* File created the 10/04/2018 at 13:21:52 by julian.frabel@epitech.eu */

/**
** \file nn_settings.h
** \brief Header containing default settings infos
*/

#ifndef __NN_SETTINGS__H_
	#define __NN_SETTINGS__H_

	#include <stdbool.h>

	#ifndef NN_DISPLAY_DEBUG_MESSAGES
		/** Display the debug messages in the console (error output) */
		#define NN_DISPLAY_DEBUG_MESSAGES false
	#endif /* !NN_DISPLAY_DEBUG_MESSAGES */

	#ifndef NN_DISPLAY_ERROR_MESSAGES
		/** Display the error messages in the console (error output) */
		#define NN_DISPLAY_ERROR_MESSAGES true
	#endif /* !NN_DISPLAY_ERROR_MESSAGES */

	#ifndef NN_DEFAULT_LEARNING_RATE
		/** Default learning rate */
		#define NN_DEFAULT_LEARNING_RATE 0.1
	#endif /* !NN_DEFAULT_LEARNING_RATE */

	#ifndef NN_DEFAULT_EXPLORE_PROB
		/** Default exploration probability */
		#define NN_DEFAULT_EXPLORE_PROB 0.99
	#endif /* !NN_DEFAULT_EXPLORE_PROB */

	#ifndef NN_DEFAULT_EXPLORE_DECAY
		/** Each step will decrease the explore probability */
		#define NN_DEFAULT_EXPLORE_DECAY 0.01
	#endif /* !NN_DEFAULT_EXPLORE_DECAY */

	#ifndef NN_DEFAULT_MIN_EXPLORE_PROB
		/** Minimal exploration probability */
		#define NN_DEFAULT_MIN_EXPLORE_PROB 0.1
	#endif /* !NN_DEFAULT_MIN_EXPLORE_PROB */

	#ifndef NN_DEFAULT_EPISODE_TRAIN
		/** Default number of episode run */
		#define NN_DEFAULT_NB_EPISODE 10000
	#endif /* !NN_DEFAULT_EPISODE_TRAIN */

	#ifndef NN_DEFAULT_FUTUR_REWARD_DISCOUNT
		/** Default futur reward discount */
		#define NN_DEFAULT_FUTUR_REWARD_DISCOUNT 0.5
	#endif /* !NN_DEFAULT_FUTUR_REWARD_DISCOUNT */

	#ifndef NN_DEFAULT_STEP_BEFORE_FINAL
		/** Default number of state before episode is aborted */
		#define NN_DEFAULT_STEP_BEFORE_BREAK 10000
	#endif /* !NN_DEFAULT_STEP_BEFORE_FINAL */

	#ifndef NN_DEFAULT_TRAINING_BATCH_SIZE
		/** Size of a training batch */
		#define NN_DEFAULT_TRAINING_BATCH_SIZE 32
	#endif /* !NN_DEFAULT_TRAINING_BATCH_SIZE */

	#ifndef REPLAY_MEM_SIZE
		/** Size of the replay memort size for reinforcement learning*/
		#define REPLAY_MEM_SIZE 5000
	#endif /* !REPLAY_MEM_SIZE */

#endif /* !__NN_SETTINGS__H_ */