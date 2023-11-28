// Integrator.h
// ~~~~~~~~~~~~
// Defines the Integrator interface.
#include <string>

#include "KeyPointsCollector.h"

class Integrator {

  // Name of file we are analyzing.
  const std::string filename;

  std::unique_ptr<KeyPointsCollector> kpc;

public:
  Integrator(const std::string &filename)
      : filename(std::move(filename)),
        kpc(std::make_unique<KeyPointsCollector>(filename)) {}
};
