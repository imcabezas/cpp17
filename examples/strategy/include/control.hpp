#pragma once

#include "./input_output.hpp"
#include "./problem_interface.hpp"
#include "./solver.hpp"

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief Orchestrates the overall control flow of the application.
 *
 * This class uses an IProblem implementation and an InputOutput handler to
 * load data, process it, and save the results.
 */
class Control {
 public:
  /**
   * @brief Constructs a Control object with a specific problem solver.
   * @param problem A unique pointer to an object implementing the IProblem
   *                interface. The Control object takes ownership.
   */
  explicit Control(std::unique_ptr<IProblem> problem);

  /**
   * @brief Executes the main logic: load, compute, save.
   * @param input_file The path to the file containing input data.
   * @param output_file The path where the results will be saved.
   * @return True on success, false if any step fails.
   */
  bool Compute(const std::filesystem::path& input_file,
               const std::filesystem::path& output_file);

 private:
  // Member variables use the Google C++ Style Guide suffix _.
  std::unique_ptr<IProblem> problem_;
  InputOutput io_handler_;
  std::vector<int> input_data_;
  std::vector<std::string> output_data_;
};