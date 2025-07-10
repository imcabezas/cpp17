#include "../include/problem_interface.hpp"



std::vector<std::string> IProblem::Compute(
    const std::vector<int>& data) const {
  std::vector<std::string> results;
  // Reserve space to avoid multiple reallocations.
  results.reserve(data.size());

  for (const int value : data) {
    results.push_back(CoreProblem(value));
  }
  return results;
}