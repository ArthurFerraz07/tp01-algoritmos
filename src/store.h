#ifndef STORE_H
#define STORE_H

#include "untils.h"
#include "localization.h"
#include "client.h"

using namespace std;

class Store {
  public:
  int id, originalStock, index;
  bool isActive;
  Localization localization;
  vector<Client> clientsPreferred;
  vector<Client> clients;

  Store();
  Store(int id_, int index_, int stock_, int x, int y);

  void addClient(Client client);
  void attemptSchedule(vector<Store> &stores, Client &client);
  void print();
  void pushClient(Client client);
  void removeWorseClient();

  bool hasStock();
};

#endif
