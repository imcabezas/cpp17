#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

/**
 * @brief A utility class for handling file input and output.
 */
class InputOutput {
 public:
  /**
   * @brief Loads a list of integers from a file.
   *
   * Each line in the file is expected to contain one integer.
   *
   * @param file_path The path to the input file.
   * @return An std::optional containing the vector of integers on success,
   *         or std::nullopt on failure (e.g., file not found).
   */
  std::optional<std::vector<int>> LoadData(
      const std::filesystem::path& file_path) const;

  /**
   * @brief Saves a list of strings to a file.
   *
   * Each string is written to a new line in the file.
   *
   * @param file_path The path to the output file.
   * @param data The vector of strings to save.
   * @return True on success, false on failure.
   */
  bool SaveData(const std::filesystem::path& file_path,
                const std::vector<std::string>& data) const;
};