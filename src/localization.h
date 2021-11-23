#ifndef LOCALIZATION_H
#define LOCALIZATION_H

// Project libraries
#include "untils.h"

class Localization {
  public:
  // Attributes
  int x, y;

  // Default constructor
  Localization();

  // Constructor
  Localization(int x_, int y_);

  // Calculate the distance to other localization
  int distance(Localization other);

  // Print localization attributes
  void print();
};

#endif
