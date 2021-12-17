// Project libraries
#include "client.h"

using namespace std;

Client getClient(vector<Client> &clients, int id) {
  for(int i = 0; i < clients.size(); i++){
    if(clients[i].id == id){
      return clients[i];
    }
  }
  return Client();
}

// Default constructor
Client::Client(){
  scheduledStoreId = -1;
}

// Constructor
Client::Client(int id_, int index_, int age_, string uf_, string paymentMethod_, int x, int y){
  id = id_;
  index = index_;
  age = age_;
  uf = uf_;
  paymentMethod = paymentMethod_;
  localization = Localization(x, y);
  isActive = true;
  scheduledStoreId = -1;
}

// // Add store on storesPreferred list
// void Client::addStore(Store store){

//   if(storesPreferred.empty()){
//     storesPreferred.push_back(store);
//   } else {
//     std::vector<Store>::iterator it;
//     int i = 0;
//     int insert = 0;
//     for(it = storesPreferred.begin(); it != storesPreferred.end(); it++){
//       if(storesPreferred[i].localization.distance(localization) > store.localization.distance(localization) ||
//          (storesPreferred[i].localization.distance(localization) == store.localization.distance(localization) && storesPreferred[i].id > store.id)){
//         insert = 1;
//         storesPreferred.insert(it, store);
//         return;
//       }
//       i++;
//     }
//     if(insert == 0){
//       storesPreferred.push_back(store);
//     }
//   } 
// }

// // attempt to schedule a visit to a store
// void Client::attemptSchedule(Store &store){
//   if(!store.hasStock()){
//     return;
//   }

//   if(!scheduledStore.isActive){
//     store.clientIds.push_back(id);
//     scheduledStore = store;
//   }
// }

// Get client payment method score
int Client::paymentMethodScore(){
  if(paymentMethod == "DINHEIRO"){
    return 1;
  } else if(paymentMethod == "DEBITO"){
    return 2;
  } else if(paymentMethod == "CREDITO"){
    return 3;
  } else {
    throw invalid_argument("Invalid payment method");
  }
}

// Print client attributes
void Client::print(){
  cout << "Client: " << id << endl;
  cout << "Index: " << index << endl;
  cout << "Age: " << age << endl;
  cout << "UF: " << uf << endl;
  cout << "Payment Method: " << paymentMethod << endl;
  cout << "Ticket: " << ticket() << endl;
  cout << "Active: " << isActive << endl;
  cout << "Scheduled Store: " << scheduledStoreId << endl;
  localization.print();
  cout << "]" << endl;
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
