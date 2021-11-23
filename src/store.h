#ifndef STORE_H
#define STORE_H

#include "untils.h"
#include "localization.h"

using namespace std;

class Store {
  public:
  int id, originalStock;
  Localization localization;

  Store(int id_, int stock_, int x, int y);

  void print();
  int currentStock();
};

#endif
