#ifndef STORE_H
#define STORE_H

#include "untils.h"
#include "localization.h"

using namespace std;

class Store {
  public:
  // Attributes
  int id, stock;
  Localization localization;

  // Constructor
  Store(int id_, int stock_, int x, int y);

  // Print localization attributes
  void print();
};

#endif
