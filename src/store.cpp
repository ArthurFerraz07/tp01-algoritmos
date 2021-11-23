#include "store.h"

using namespace std;

// Constructor
Store::Store(int id_, int stock_, int x, int y) {
  id = id_;
  originalStock = stock_;
  localization = Localization(x, y);
}

// Print attributes
void Store::print() {
  cout << "Store: " << id << endl;
  cout << "Stock: " << originalStock << endl;
  localization.print();
  cout << endl;
}

// Calculate current stock
int Store::currentStock() {
  return originalStock;
}
