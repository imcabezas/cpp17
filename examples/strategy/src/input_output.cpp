#include "../include//input_output.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <optional>

std::optional<std::vector<int>> InputOutput::LoadData(
    const std::filesystem::path& file_path) const {
  std::ifstream input_file(file_path);
  if (!input_file.is_open()) {
    return std::nullopt;  // File could not be opened.
  }

  std::vector<int> data;
  std::string line;
  while (std::getline(input_file, line)) {
    try {
      // Skip empty lines.
      if (!line.empty()) {
        data.push_back(std::stoi(line));
      }
    } catch (const std::invalid_argument& e) {
      // Line is not a valid integer
      // Nothing to do, just ignore the line.
    } catch (const std::out_of_range& e) {
      // Integer value is out of range.
      // Nothing to do, just ignore the line.
    }
  }

  return data;
}

bool InputOutput::SaveData(const std::filesystem::path& file_path,
                           const std::vector<std::string>& data) const {
  std::ofstream output_file(file_path);
  if (!output_file.is_open()) {
    return false;
  }

  for (const auto& line : data) {
    output_file << line << '\n';
  }

  return output_file.good();
}