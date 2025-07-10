#pragma once

#include "./problem_interface.hpp"

#include <string>
#include <vector>

/**
 * @brief A concrete implementation of the IProblem interface.
 *
 * This class provides a specific algorithm for solving the problem defined by
 * IProblem. It can be provided to a controller class at runtime.
 */
class Solver final : public IProblem {
 public:
 // std::vector<std::string> Compute(
 //     const std::vector<int>& data) const override;

 protected:
  std::string CoreProblem(int value) const override;
};