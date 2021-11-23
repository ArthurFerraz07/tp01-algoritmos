#ifndef CLIENT_H
#define CLIENT_H

// Project libraries
#include "untils.h"
#include "localization.h"

using namespace std;

class Client {
  public:
  int id, age;
  string uf, paymentMethod;
  Localization localization;
  
  Client();
  Client(int id_, int age_, string uf_, string paymentMethod_, int x, int y);
  int paymentMethodScore();
  void print();
  float ticket();
  int ufScore();
};

#endif
