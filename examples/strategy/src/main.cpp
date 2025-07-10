#include <filesystem>
#include <iostream>
#include <memory>
#include <utility>


#include "../include/input_output.hpp"
#include "../include/control.hpp"


int main() { 
  
  std::cout << "Strategy pattern!\n";

  //io files
  const std::filesystem::path input_file = "../data/input.txt";
  const std::filesystem::path output_file = "../data/output.txt";

  //Solver object as the strategy object
  auto solver = std::make_unique<Solver>();

  //Control object injecting the solver object
  Control control(std::move(solver));

  //Compute method of control object
  const bool success = control.Compute(input_file, output_file);

  if (success){
    std::cout << "Computation successful. Results saved to " << output_file << std::endl;
  }
  else {
    std::cerr << "Computation failed." << std::endl;
  }
  

  /*
  //InputOuyput object reading input.txt for manul testing puerposes
  InputOutput io;

  //string view for the input file
  std::string input_file = "input.txt";
  
  auto data = io.LoadData(input_file);
  if (data) {
    for (auto value : *data) {
      std::cout << value << std::endl;
    }
  }
  else {
    std::cerr << "Failed to load data from " << input_file << std::endl;
  }
  //option for checking non-existent file
  */

}