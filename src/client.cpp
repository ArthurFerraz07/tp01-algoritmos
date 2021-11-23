// Project libraries
#include "client.h"

using namespace std;

// Default constructor
Client::Client(){}

// Constructor
Client::Client(int id_, int age_, string uf_, string paymentMethod_, int x, int y){
  id = id_;
  age = age_;
  uf = uf_;
  paymentMethod = paymentMethod_;
  localization = Localization(x, y);
}

// Get client payment method score
int Client::paymentMethodScore(){
  if(paymentMethod == "DINHEIRO"){
    return 1;
  } else if(paymentMethod == "DEBITO"){
    return 2;
  } else if(paymentMethod == "CREDITO"){
    return 3;
  } else {
    throw invalid_argument("Invalid UF");
  }
}

// Print client attributes
void Client::print(){
  cout << "Client: " << id << endl;
  cout << "Age: " << age << endl;
  cout << "UF: " << uf << endl;
  cout << "Payment Method: " << paymentMethod << endl;
  cout << "Ticket: " << ticket() << endl;
  localization.print();
  cout << endl;
}

// Calculate client ticket
float Client::ticket(){
  return (abs(60 - age) + ufScore() / paymentMethodScore());
}

// Calculate client UF score
int Client::ufScore(){
  if(uf == "MG"){
    return 0;
  } else if(uf == "PR"){
    return 10;
  } else if(uf == "SP"){
    return 20;
  } else if(uf == "SC"){
    return 30;
  } else if(uf == "RJ"){
    return 40;
  } else if(uf == "RN"){
    return 50;
  } else if(uf == "RS"){
    return 60;
  } else {
    throw invalid_argument("Invalid UF");
  }
}
