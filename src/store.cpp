#include "store.h"
#include "client.h"

using namespace std;

// Default constructor
Store::Store(){}

// Constructor
Store::Store(int id_, int stock_, int x, int y) {
  id = id_;
  originalStock = stock_;
  localization = Localization(x, y);
  isActive = true;
}

// Print attributes
void Store::print() {
  cout << "Store: " << id << endl;
  cout << "Stock: " << originalStock << endl;
  cout << "Active: " << isActive << endl;
  cout << "Client IDs: [ ";
  cout << clientIds.size() << " ]" << endl;
  for (int i = 0; i < clientIds.size(); i++) {
    cout << clientIds[i] << " ";
  }
  // cout << "]" << endl;
  localization.print();
  cout << endl;
}

// Push client id to client ids vector
void Store::pushClientId(int id_){
  clientIds.push_back(id_);
}

// Check if store has stock
bool Store::hasStock() {
  return originalStock - clientIds.size() > 0;
}
