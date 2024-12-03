#include "cholesky.hpp"
#include <chrono>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

namespace fs = std::filesystem;

std::string setup_alalysis() {
  const fs::path analysis_box{"./analysis/out"};
  if (!fs::exists(analysis_box))
    fs::create_directory(analysis_box);
  time_t timestamp;
  time(&timestamp);
  char buffer[20];
  strftime(buffer, sizeof(buffer), "%m%d%Y_%H%M%S", localtime(&timestamp));
  std::string filename = std::string(analysis_box.relative_path()) +
                         "/output_" + std::string(buffer) + ".csv";
  return filename;
}

void benchmark(std::vector<int> NROWS) {
  std::string file_name = setup_alalysis();
  std::ofstream outputFile(file_name);
  outputFile << "NROWS,Time" << std::endl;
  for (int nrow : NROWS) {
    double **A = (double **)calloc(nrow, sizeof *A);
    for (size_t i = 0; i < nrow; i++) {
      A[i] = (double *)calloc(nrow, sizeof *A[i]);
    }
    Cholesky::fill_random(nrow, A);
    double **L = (double **)calloc(nrow, sizeof *L);
    for (size_t i = 0; i < nrow; i++) {
      L[i] = (double *)calloc(nrow, sizeof *L[i]);
    }
    Cholesky::init_zero_matrix(nrow, L);
    auto start = std::chrono::high_resolution_clock::now();
    Cholesky::naive_cholesky(A, nrow, L);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    outputFile << nrow << "," << duration.count() << std::endl;
  }
  outputFile.close();
  std::cout << "Results written to " << file_name << std::endl;
}

int main() {
  std::vector<int> NROWS = {100, 200, 300, 500, 800, 1000, 2000, 5000};
  benchmark(NROWS);
  return 0;
}