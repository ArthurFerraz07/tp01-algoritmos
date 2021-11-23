#ifndef CLIENT_H
#define CLIENT_H

// Project libraries
#include "untils.h"
#include "localization.h"
#include "store.h"

using namespace std;

class Client {
  public:
  int id, age;
  string uf, paymentMethod;
  Localization localization;
  vector<Store> storesPreferred;
  
  Client();
  Client(int id_, int age_, string uf_, string paymentMethod_, int x, int y);

  void addStore(Store store);
  void print();

  int paymentMethodScore();
  int ufScore();

  float ticket();
};

#endif
