#include "cholesky.hpp"
#include "doctest/doctest.hpp"
#include <stdlib.h>

TEST_CASE("Test the cholesky implementation") {
  SUBCASE("Should fill a matrix with zeros") {
    int n = 3;
    double **A = (double **)calloc(n, sizeof *A);
    for (size_t i = 0; i < n; i++) {
      A[i] = (double *)calloc(n, sizeof *A[i]);
    }
    Cholesky::init_zero_matrix(n, A);
    CHECK(A[0][0] == 0);
    CHECK(A[0][1] == 0);
    CHECK(A[0][2] == 0);
    CHECK(A[1][0] == 0);
    CHECK(A[1][1] == 0);
    CHECK(A[1][2] == 0);
    CHECK(A[2][0] == 0);
    CHECK(A[2][1] == 0);
    CHECK(A[2][2] == 0);
  }
  SUBCASE("Should fill a matrix with given data") {
    int n = 3;
    double **A = (double **)calloc(n, sizeof *A);
    for (size_t i = 0; i < n; i++) {
      A[i] = (double *)calloc(n, sizeof *A[i]);
    }
    double data[] = {2, 1, 1, 1, 3, 1, 1, 1, 2};
    Cholesky::bulk_insert(n, A, data);
    CHECK(A[0][0] == 2);
    CHECK(A[0][1] == 1);
    CHECK(A[0][2] == 1);
    CHECK(A[1][0] == 1);
    CHECK(A[1][1] == 3);
    CHECK(A[1][2] == 1);
    CHECK(A[2][0] == 1);
    CHECK(A[2][1] == 1);
    CHECK(A[2][2] == 2);
  }
  SUBCASE("Should decompose the matrix A into LL*") {
    int n = 3;
    double **A = (double **)calloc(n, sizeof *A);
    for (size_t i = 0; i < n; i++) {
      A[i] = (double *)calloc(n, sizeof *A[i]);
    }
    double **L = (double **)calloc(n, sizeof *L);
    for (size_t i = 0; i < n; i++) {
      L[i] = (double *)calloc(n, sizeof *L[i]);
    }
    double data[] = {2, 1, 1, 1, 3, 1, 1, 1, 2};
    Cholesky::bulk_insert(n, A, data);
    Cholesky::naive_cholesky(A, n, L);
    CHECK(L[0][0] == doctest::Approx(1.41421).epsilon(0.01));
    CHECK(L[0][1] == 0);
    CHECK(L[0][2] == 0);
    CHECK(L[1][0] == doctest::Approx(0.707107).epsilon(0.01));
    CHECK(L[1][1] == doctest::Approx(1.58114).epsilon(0.01));
    CHECK(L[1][2] == 0);
    CHECK(L[2][0] == doctest::Approx(0.707107).epsilon(0.01));
    CHECK(L[2][1] == doctest::Approx(0.316228).epsilon(0.01));
    CHECK(L[2][2] == doctest::Approx(1.18322).epsilon(0.01));
  }
}