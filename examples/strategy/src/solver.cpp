#include "solver.hpp"

#include <algorithm>
#include <array>
#include <charconv>  
#include <numeric>  // For std::accumulate
#include <string>   // For std::to_string
#include <string_view>


/*
std::vector<std::string> Solver::Compute(
    const std::vector<int>& data) const {
  std::vector<std::string> results;
  // Reserve space to avoid multiple reallocations.
  results.reserve(data.size());

  for (const int value : data) {
    results.push_back(CoreProblem(value));
  }
  return results;
}
*/

// A simple example implementation for the core problem.
// For example, it could check if a number is prime, or find its factors.
// Here, we'll just format it into a string.
std::string Solver::CoreProblem(int value) const {
  std::string result = std::to_string(value);
  result.reserve(result.size()+10);
  result += " ";
  const std::string_view classification = (value%2 == 0) ? "even": "odd";
  result.append(classification);
  return result;   
  //--return "Processed value: " + std::to_string(value);
}