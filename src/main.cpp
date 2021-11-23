// Project libraries
#include "untils.h"
#include "store.h"
#include "client.h"

using namespace std;

int main(){
  // Read grid info
  int gridH, gridW;
  cin >> gridH >> gridW;

  // Read stores count
  int storeCount;
  cin >> storeCount;

  // Read stores info
  vector<Store> stores;
  for(int i = 0; i < storeCount; i++){
    int storeId, storeStock, storeX, storeY;
    storeId = i + 1;

    cin >> storeStock >> storeX >> storeY;

    stores.push_back(Store(storeId, storeStock, storeX, storeY));
  }

  // // Print scenario info
  // for(int i = 0; i < storeCount; i++){
  //   stores[i].print();
  // }

  // Read clients count
  int clientCount;
  cin >> clientCount;

  // Read clients info
  vector<Client> clients;
  for(int i = 0; i < clientCount; i++){
    int clientId, clientAge, clientX, clientY;
    string clientUf, clientPaymentMethod;
    clientId = i + 1;

    cin >> clientAge >> clientUf >> clientPaymentMethod >> clientX >> clientY;

    clients.push_back(Client(clientId, clientAge, clientUf, clientPaymentMethod, clientX, clientY));
  }

  // Print scenario info
  for(int i = 0; i < clientCount; i++){
    clients[i].print();
  }

  return 0;
}
