// Integrator.cpp
// ~~~~~~~~~~~~~~
// Implementation of the Integrator interface.
#include "Integrated.h"
#include "KeyPointsCollector.h"
#include <algorithm>
#include <sstream>

std::string Integrator::analyzeBPTrace(const std::string trace) {

  // BP trace lines
  std::vector<std::string> lines;
  std::string currentLine;
  std::istringstream stream(trace);

  // Map to hold count
  std::map<std::string, unsigned> counts;

  // Split trace
  while (std::getline(stream, currentLine, '\n')) {
    lines.push_back(currentLine);
  }

  // Get counts
  for (const std::string line : lines) {
    if (MAP_FIND(counts, line))
      continue;
    else {
      counts[line] = std::count(lines.begin(), lines.end(), line);
    }
  }

  // Get BP with highest count
  int max = 0;
  std::string max_string;
  for (const std::pair<std::string, unsigned> bp : counts) {
    if (bp.second > max) {
      max = bp.second;
      max_string = bp.first;
    }
  }
  return max_string;
}

int Integrator::getBranchPointLocation(std::string bp) {

  // Get ref to branch dictionary
  std::map<unsigned, std::map<unsigned, std::string>> branchDict =
      kpc->getBranchDictionary();

  for (const std::pair<unsigned, std::map<unsigned, std::string>> outer :
       branchDict) {
    for (const std::pair<unsigned, std::string> inner : outer.second) {
      if (inner.second == bp) {
        return outer.first;
      }
    }
  }
  return -1;
}
