#pragma once

#include <climits>
#include <vector>
#include "../parallel.h"
#include "../timer.h"
#include "../util.h"
#include "sparse_vector.h"

class SparseMatrix {
 public:
  double get_diag(const size_t i) const { return diag[i]; }

  void cache_diag();

  std::vector<double> mul(const std::vector<double>& vec) const;

  void append_elem(const size_t i, const size_t j, const double& elem);

  void set_dim(const size_t dim);

  void clear();

  void sort_row(const size_t i);

 private:
  std::vector<SparseVector> rows;

  std::vector<double> diag_local;

  std::vector<double> diag;

  std::vector<double> reduce_sum(const std::vector<double>& vec) const;
};