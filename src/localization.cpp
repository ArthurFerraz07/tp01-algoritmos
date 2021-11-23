// Project libraries
#include "localization.h"

using namespace std;

// Default constructor
Localization::Localization(){}

// Constructor
Localization::Localization(int x_, int y_) {
  x = x_;
  y = y_;
}

// Calculate the distance to other localization
int Localization::distance(Localization other){
  int dx = abs(x - other.x);
  int dy = abs(y - other.y);

  int diagonalSteps = min(dx, dy);
  int straightSteps = max(dx, dy) - diagonalSteps;

  int d = diagonalSteps + straightSteps;

  return d == 0 ? d : d - 1;
};

// Print localization attributes
void Localization::print(){
  cout << "Localization: (" << x << ", " << y << ")" << endl;
}
