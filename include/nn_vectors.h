/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Header for the vector part
*/

/* File created the 10/04/2018 at 13:13:44 by julian.frabel@epitech.eu */

#ifndef __NN_VECTORS__H_
	#define __NN_VECTORS__H_

	typedef struct nn_vector_s nn_vector_t;

	/***
	** \brief Structure representing a n dimentional vector
	*/
	struct nn_vector_s {
		unsigned int nb_values; /**< Number of dimentions */
		float *values; /**< Values in the vector */
	};

	/***
	** \brief Function creating a nb_values dimentional vector
	** @param nb_values number of dimention in the vector
	**
	** Create a new vector with all values set to 0.0.
	** Return the new vector.
	*/
	nn_vector_t *create_empty_nn_vector(int nb_values);
	/***
	** \brief Function creating a nb_values dimentional vector
	** @param array the defaults values of the vector
	** @param nb_values number of dimention in the vector
	**
	** Create a new vector with all values set to the array values.
	** Return the new vector.
	*/
	nn_vector_t *create_nn_vector_from_array(float *array, int nb_values);
	/***
	** \brief Function destroying a nb_values dimentional vector
	** @param vector the vector to destroy
	**
	** Destroy the given vector.
	*/
	void destroy_nn_vector(nn_vector_t *vector);

	/***
	** \brief Function that multiply a vector by a multiplicator
	** @param vector the vector to multiply
	** @param mul the multiplicator to apply
	**
	** Multply the vector by the given multiplicator.
	** Return NULL in case of error, the result as a vector otherwise.
	*/
	nn_vector_t *nn_vector_multiply(nn_vector_t *vector, float mul);
	/***
	** \brief Function that divide a vector by a divisor
	** @param vector the vector to divide
	** @param divisor the divisor to apply
	**
	** Divide the vector by the given divisor.
	** Return NULL in case of error, the result as a vector otherwise.
	*/
	nn_vector_t *nn_vector_divide(nn_vector_t *vector, float divisor);
	/***
	** \brief Function that add two vectors together
	** @param a the first vector
	** @param b the second vector
	**
	** Add the vector together.
	** Return NULL in case of error, the result as a vector otherwise.
	*/
	nn_vector_t *nn_vector_add(nn_vector_t *a, nn_vector_t *b);
	/***
	** \brief Function that substract two vectors together
	** @param a the first vector
	** @param b the second vector
	**
	** Substract the vector together.
	** Return NULL in case of error, the result as a vector otherwise.
	*/
	nn_vector_t *nn_vector_sub(nn_vector_t *a, nn_vector_t *b);

	/***
	** \brief Function that realise a dot product of vectors
	** @param a the first vector
	** @param b the second vector
	**
	** Realize the dot product between two vectors.
	** Return the result. Return 0 if an error occured.
	*/
	float nn_vector_dot_product(nn_vector_t *a, nn_vector_t *b);

#endif /* !__NN_VECTORS__H_ */