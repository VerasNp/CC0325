#include "cholesky.hpp"
#include <cmath>
#include <iostream>

void Cholesky::naive_cholesky(double **A, int n, double **L) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      double sum = 0;
      if (i > j) {
        for (size_t k = 0; k < j; k++) {
          sum += L[j][k] * L[i][k];
        }
        L[i][j] = (1 / L[j][j]) * (A[i][j] - sum);
      } else {
        for (size_t k = 0; k < j; k++) {
          sum += L[j][k] * L[j][k];
        }
        L[j][j] = std::sqrt(A[j][j] - sum);
      }
    }
  }
}

void Cholesky::init_zero_matrix(int n, double **M) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      M[i][j] = 0;
    }
  }
}

void Cholesky::bulk_insert(int n, double **M, double *data) {
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      M[i][j] = data[i * n + j];
    }
  }
}

void Cholesky::fill_random(int n, double **M) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      M[i][j] = rand() / RAND_MAX;
    }
  }
}
