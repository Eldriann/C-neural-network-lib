##
## EPITECH PROJECT, 2017
## nn_lib
## File description:
## Make the nn lib
##

SRC_DIR_VECTOR	=	$(realpath src/vectors)

SRC_FILES_VECTOR=	vector_core.c					\
			vector_scalar.c					\
			vector_dot_product.c				\
			vector_elementwise.c

SRC_DIR_MATRIX	=	$(realpath src/matrix)

SRC_FILES_MATRIX=	matrix_core.c					\
			matrix_scalar.c					\
			matrix_elementwise.c				\
			matrix_multiply.c				\
			matrix_transpose.c				\
			matrix_randomize.c				\
			matrix_map.c					\
			matrix_clone.c

SRC_DIR_MISC	=	$(realpath src/miscellanous)

SRC_FILES_MISC	=	nn_puts.c					\
			nn_sigmoid.c					\
			nn_tanh.c					\
			nn_linear.c					\
			max_reward.c

SRC_DIR_NN	=	$(realpath src/neural_network)

SRC_FILES_NN	=	neural_network_core.c				\
			neural_network_feed_forward.c			\
			neural_network_backpropagate.c			\
			neural_network_train_supervised.c		\
			neural_network_save.c				\
			neural_network_checksum.c			\
			neural_network_create_from_file.c		\
			neural_network_train_reinforced.c		\
			neural_network_store_replay_memory.c

SRC		=	$(addprefix $(SRC_DIR_VECTOR)/, $(SRC_FILES_VECTOR)) \
			$(addprefix $(SRC_DIR_MISC)/, $(SRC_FILES_MISC)) \
			$(addprefix $(SRC_DIR_MATRIX)/, $(SRC_FILES_MATRIX)) \
			$(addprefix $(SRC_DIR_NN)/, $(SRC_FILES_NN))

OBJ		=	$(SRC:%.c=%.o)

NAME		=	libnn.a

INCLUDE		=	-I include

CFLAGS		=	-Wall -Wextra -Wno-unknown-pragmas
CFLAGS		+=	$(INCLUDE)

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(AR) -rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re

tests_run:
		$(MAKE) -C tests
		./tests/test --verbose

tests_clear:
		$(MAKE) fclean -C tests