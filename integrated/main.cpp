// main.cpp
// ~~~~~~~~
// Main execution for the Integrated KPC and SIFD
#include <iostream>
#include <fstream>
#include <string>

int main(void) {
  
  // Get filename
  std::string filename;
  std::cout << "Enter a file name for analysis: ";
  std::cin >> filename;

  if (!static_cast<bool>(std::ifstream(filename).good())) {
    std::cerr << "There was an issue opening " << filename
              << " for analysis, exiting!\n";
    exit(EXIT_FAILURE);
  }

}
