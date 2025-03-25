#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec);

void selection_sort(std::vector<int> & vec);

size_t quick_sort_partition(std::vector<float> & vec, size_t left, size_t right, size_t const pivot);
void quick_sort(std::vector<float> & vec, size_t const left, size_t const right);
void quick_sort(std::vector<float> & vec);


std::vector<int> generate_random_vector(size_t const size, int const max);

int search(std::vector<int> const& vec, int val);

