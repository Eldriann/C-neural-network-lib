##
## EPITECH PROJECT, 2017
## nnlib
## File description:
## Makefile for the units tests of the nnlib
##

## SOURCES
SRC_DIR_MISC	=	$(realpath ../src/miscellanous)

SRC_FILES_MISC	=	nn_puts.c					\
			nn_sigmoid.c					\
			nn_tanh.c					\
			nn_linear.c					\
			max_reward.c

SRC_DIR_VECTOR	=	$(realpath ../src/vectors)

SRC_FILES_VECTOR=	vector_core.c					\
			vector_scalar.c					\
			vector_dot_product.c				\
			vector_elementwise.c

SRC_DIR_MATRIX	=	$(realpath ../src/matrix)

SRC_FILES_MATRIX=	matrix_core.c					\
			matrix_scalar.c					\
			matrix_elementwise.c				\
			matrix_multiply.c				\
			matrix_transpose.c				\
			matrix_randomize.c				\
			matrix_map.c					\
			matrix_clone.c

SRC_DIR_NN	=	$(realpath ../src/neural_network)

SRC_FILES_NN	=	neural_network_core.c				\
			neural_network_feed_forward.c			\
			neural_network_backpropagate.c			\
			neural_network_train_supervised.c		\
			neural_network_save.c				\
			neural_network_checksum.c			\
			neural_network_create_from_file.c		\
			neural_network_train_reinforced.c		\
			neural_network_store_replay_memory.c

SRC		=	$(addprefix $(SRC_DIR_MISC)/, $(SRC_FILES_MISC)) \
			$(addprefix $(SRC_DIR_VECTOR)/, $(SRC_FILES_VECTOR)) \
			$(addprefix $(SRC_DIR_MATRIX)/, $(SRC_FILES_MATRIX)) \
			$(addprefix $(SRC_DIR_NN)/, $(SRC_FILES_NN))

## TESTS SOURCES
TESTS_DIR_MISC	=	$(realpath ./src/miscellanous)

TESTS_FILES_MISC=	tests_nn_puts.c

TESTS_DIR_VECT	=	$(realpath ./src/vectors)

TESTS_FILES_VECT=	tests_vector_core.c				\
			tests_vector_scalar.c				\
			tests_vector_dot_product.c			\
			tests_vector_elementwise.c

TESTS_DIR_MAT	=	$(realpath ./src/matrix)

TESTS_FILES_MAT	=	tests_matrix_core.c				\
			tests_matrix_scalar.c				\
			tests_matrix_elementwise.c			\
			tests_matrix_multiply.c				\
			tests_matrix_transpose.c			\
			tests_matrix_randomize.c			\
			tests_matrix_map.c				\
			tests_matrix_clone.c

TESTS_DIR_NN	=	$(realpath ./src/neural_network)

TESTS_FILES_NN	=	tests_neural_network_core.c			\
			tests_neural_network_feed_forward.c		\
			tests_neural_network_train_supervised.c

SRC_TESTS	=	$(addprefix $(TESTS_DIR_MISC)/, $(TESTS_FILES_MISC)) \
			$(addprefix $(TESTS_DIR_VECT)/, $(TESTS_FILES_VECT)) \
			$(addprefix $(TESTS_DIR_MAT)/, $(TESTS_FILES_MAT)) \
			$(addprefix $(TESTS_DIR_NN)/, $(TESTS_FILES_NN))

## RULES
OBJ		=	$(SRC:%.c=%.o) $(SRC_TESTS:%.c=%.o)

CCTMP		=	$(SRC:%.c=%.gcno) $(SRC:%.c=%.gcda) $(SRC_TESTS:%.c=%.gcno) $(SRC_TESTS:%.c=%.gcda)

NAME		=	test

INCLUDE		=	-I ../include

CFLAGS		=	-Wall -Wextra --coverage -Wno-unknown-pragmas
CFLAGS		+=	$(INCLUDE)

LDFLAGS		=	-lcriterion -lgcov -lm

CC		=	gcc

all:		$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC_TESTS) $(SRC) $(LDFLAGS) $(CFLAGS)

cclean:
		$(RM) $(CCTMP)
		$(RM) *.gcno
		$(RM) *.gcda
		$(RM) *.gcov

clean:
		$(RM) $(OBJ)

fclean:		clean cclean
		$(RM) -f $(NAME)

re:		fclean all