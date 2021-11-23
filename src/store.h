#ifndef STORE_H
#define STORE_H

#include "untils.h"
#include "localization.h"

using namespace std;

class Store {
  public:
  int id, originalStock;
  bool isActive;
  Localization localization;
  vector<int> clientIds;

  Store();
  Store(int id_, int stock_, int x, int y);

  void print();
  void pushClientId(int id_);

  bool hasStock();
};

#endif
