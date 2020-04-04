#include <cmath>
#include <iostream>
#include <string>

#include "TravelAgencyConfig.h"

auto main(int argc, char* argv[]) -> int
{
  if (argc < 2) {
    std::cout << argv[0] << " Version " << TravelAgency_VERSION_MAJOR << "."
              << TravelAgency_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
