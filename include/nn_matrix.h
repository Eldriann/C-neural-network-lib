/*
** EPITECH PROJECT, 2017
** nnlib
** File description:
** Matrix header
*/

/* File created the 10/04/2018 at 17:28:32 by julian.frabel@epitech.eu */

#ifndef __MATRIX__H_
	#define __MATRIX__H_

	typedef struct nn_matrix_s nn_matrix_t;

	/***
	** \brief Structure representing a float matrix
	*/
	struct nn_matrix_s {
		int nb_columns;
		int nb_rows;
		float **values;
	};

	/***
	** \brief Create an empty matrix
	** @param rows the number of rows
	** @param columns the number of columns
	**
	** Create a new empty matrix and return it (all values at 0.0).
	** Return NULL in case of an error, the new matrix otherwise.
	*/
	nn_matrix_t *create_empty_nn_matrix(int rows, int columns);
	/***
	** \brief Destroy a given matrix
	** @param matrix the matrix to destroy
	**
	** Destroy and free a matrix.
	*/
	void destroy_nn_matrix(nn_matrix_t *matrix);
	/***
	** \brief Multiply a matrix
	** @param matrix the matrix to multiply
	** @param mul the multiplicator
	**
	** Multiply a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_multiply(nn_matrix_t *matrix, float mul);
	/***
	** \brief Divide a matrix
	** @param matrix the matrix to divide
	** @param divisor the divisor to apply
	**
	** Divide a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_divide(nn_matrix_t *matrix, float divisor);
	/***
	** \brief Add to a matrix
	** @param matrix the matrix to add to
	** @param to_add the number to add to all the matrix
	**
	** Add a number to a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_add(nn_matrix_t *matrix, float to_add);
	/***
	** \brief Add a matrix to a matrix
	** @param a the first matrix
	** @param b the second matrix
	**
	** Add a matrix to a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_add_matrix(nn_matrix_t *a, nn_matrix_t *b);
	/***
	** \brief Mutiply a matrix with a matrix of same size
	** @param a the first matrix
	** @param b the second matrix
	**
	** Multiply a matrix with a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_schur_product(nn_matrix_t *a, nn_matrix_t *b);
	/***
	** \brief Mutiply a matrix with a matrix
	** @param a the first matrix
	** @param b the second matrix
	**
	** Multiply a matrix with a matrix and return the result as a matrix.
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_multiply_matrix(nn_matrix_t *a, nn_matrix_t *b);
	/***
	** \brief Transpose a matrix
	** @param mat the matrix to transpose
	**
	** Transpose a matrix and return the result as a new matrix.
	** (transpose = columns to row and row to columns).
	** Return NULL in case of an error, the result as a matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_transpose(nn_matrix_t *mat);
	/***
	** \brief Randomize a matrix
	** @param mat the matrix to randomize
	** @param min the minimum value
	** @param max the maximum value
	**
	** Randomize a matrix.
	** Return 84 in case of an error, 0 otherwise.
	*/
	int nn_matrix_randomize(nn_matrix_t *mat, float min, float max);

	/***
	** \brief Apply on all element of a matrix a given func
	** @param mat the matrix to apply on
	** @param func the function to apply
	**
	** Apply on all element of a matrix a given function.
	** Return 84 in case of an error, 0 otherwise.
	*/
	int nn_matrix_map(nn_matrix_t *mat, float (*func)(float));
	/***
	** \brief clone a matrix
	** @param mat the matrix to clone
	**
	** Return NULL in case of an error, the identical matrix otherwise.
	*/
	nn_matrix_t *nn_matrix_clone(const nn_matrix_t *mat);

#endif /* !__MATRIX__H_ */