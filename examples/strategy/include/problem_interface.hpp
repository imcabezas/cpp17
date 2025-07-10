#pragma once

#include <string>
#include <vector>

/**
 * @brief Defines the interface for a solvable problem.
 *
 * This abstract class declares the contract for any class that can process a list
 * of integers and produce a list of strings. It follows the Strategy design
 * pattern, where concrete implementations provide specific algorithms.
 */
class IProblem {
 public:
  // A virtual destructor is essential for polymorphic base classes.
  virtual ~IProblem() = default;

  /**
   * @brief Computes a result for a batch of integer inputs.
   * @param data A vector of integers to be processed.
   * @return A vector of strings representing the results.
   */
  std::vector<std::string> Compute(
      const std::vector<int>& data) const;

 protected:
  /**
   * @brief The core processing logic for a single integer value.
   *
   * This function is intended to be called by the public Compute method.
   * @param value The single integer to process.
   * @return A string representing the result for the single value.
   */
  virtual std::string CoreProblem(int value) const = 0;
};