// Project libraries
#include "untils.h"
#include "store.h"
#include "client.h"

using namespace std;

void addClient(vector<Client> &clients, Client client ) {
  if(clients.empty()) {
    clients.push_back(client);
  } else {
    std::vector<Client>::iterator it;
    int i = 0;
    int insert = 0;
    for(it = clients.begin(); it != clients.end(); it++){
      if(clients[i].ticket() < client.ticket() ||
         (clients[i].ticket() == client.ticket() && clients[i].id < client.id)){
        insert = 1;
        clients.insert(it, client);
        return;
      }
      i++;
    }
    if(insert == 0){
      clients.push_back(client);
    }
  }
}

bool anyClientWithoutSchedule(vector<Client> &clients) {
  for(int i = 0; i < clients.size(); i++){
    if(clients[i].scheduledStoreId == -1){
      return true;
    }
  }
  return false;
}

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
    storeId = i;

    cin >> storeStock >> storeX >> storeY;

    stores.push_back(Store(storeId, storeId, storeStock, storeX, storeY));
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
    clientId = i;

    cin >> clientAge >> clientUf >> clientPaymentMethod >> clientX >> clientY;

    Client current_client;

    current_client = Client(clientId, 0, clientAge, clientUf, clientPaymentMethod, clientX, clientY);

    addClient(clients, current_client);
  }

  // For each store, order clients by prererence
  for(int i = 0; i < storeCount; i++){
    for(int j = 0; j < clientCount; j++){
      clients[j].index = j;
      stores[i].addClient(clients[j]);
    }
  }

    for(int i = 0; i < storeCount; i++){
    // stores[i].print();
  }


  // For each store, attempt to schedule a visit with each client
  // while(anyClientWithoutSchedule(clients)){
    for(int i = 0; i < storeCount; i++){
      for(int j = 0; j < stores[i].clientsPreferred.size(); j++){
        stores[i].attemptSchedule(stores, clients[stores[i].clientsPreferred[j].index]);
      }
    }
  // }

  // for(int i = 0; i < clientCount; i++){
  //   for(int k = 0; k < clients[i].storesPreferred.size(); k++){
  //     clients[i].attemptSchedule(stores[clients[i].storesPreferred[k].id]);
  //   }
  // }

  // Print scenario info
  for(int i = 0; i < clientCount; i++){
    // clients[i].print();
  }

  // Print scenario info
  for(int i = 0; i < storeCount; i++){
    stores[i].print();
  }

  return 0;
}
