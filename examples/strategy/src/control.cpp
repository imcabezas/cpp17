#include "../include/control.hpp"

#include <utility>  // For std::move

Control::Control(std::unique_ptr<IProblem> problem)
    // Use std::move to transfer ownership of the unique_ptr.
    : problem_(std::move(problem)), io_handler_() {}

bool Control::Compute(const std::filesystem::path& input_file,
                      const std::filesystem::path& output_file) {
  // 1. Load data using the IO handler.
  auto loaded_data = io_handler_.LoadData(input_file);
  if (!loaded_data.has_value()) {
    // Loading failed (e.g., file not found or malformed).
    return false;
  }
  input_data_ = *loaded_data;

  // 2. Process the data using the injected problem solver.
  output_data_ = problem_->Compute(input_data_);

  // 3. Save the results.
  if (!io_handler_.SaveData(output_file, output_data_)) {
    // Saving failed.
    return false;
  }

  return true;
}