#pragma once
#include <cstddef>

namespace Cholesky {
/**
 * @brief Runs the Cholesky decomposition
 *
 * Decomposes a simetric and positive-definite matrtix into the product of a
 * lower triangular matrix and its conjugate transpose.
 *
 * @param A Simetric and positive-definite matrtix
 * @param n The matrix size
 * @param L Lower triangular matrix
 */
void naive_cholesky(double **A, int n, double **L);

/**
 * @brief Fills the matrix with zeros
 *
 * The given matrix will be filled with zeros on all elements.
 *
 * @param n The matrix size
 * @param M The matrix
 */
void init_zero_matrix(int n, double **M);

/**
 * @brief Fills the matrix
 */
void bulk_insert(int n, double **M, double *data);

/**
 * @brief Fill the matrix with randim numbers
 * 
 * @param n Number of rows
 * @param M The matrix 
 */
void fill_random(int n, double **M);
} // namespace Cholesky
