// Integrator.h
// ~~~~~~~~~~~~
// Defines the Integrator interface.
#include <string>

#include "KeyPointsCollector.h"
#include "SeminalInputFeatureDetector.h"

class Integrator {

  // Name of file we are analyzing.
  const std::string filename;

  KeyPointsCollector *kpc;
  SeminalInputFeatureDetector *sifd;

public:
  Integrator(const std::string &filename) : filename(std::move(filename)) {
    kpc = new KeyPointsCollector(filename);
    sifd = new SeminalInputFeatureDetector(filename);
  }

  ~Integrator() {
    delete kpc;
    delete sifd;
  }

  // Analyzes a BP trace and finds the most occuring branch
  std::string analyzeBPTrace(const std::string trace);

  // Gets the line location of branch point
  int getBranchPointLocation(std::string bp);

  // Get ref to KPC
  KeyPointsCollector &getKpc() { return *kpc; }

  SeminalInputFeatureDetector &getSifd() { return *sifd; }
};
