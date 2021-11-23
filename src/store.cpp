#include "store.h"

using namespace std;

// Constructor
Store::Store(int id_, int stock_, int x, int y) {
  id = id_;
  stock = stock_;
  localization = Localization(x, y);
}

void Store::print() {
  cout << "Store: " << id << endl;
  cout << "Stock: " << stock << endl;
  localization.print();
  cout << endl;
}
