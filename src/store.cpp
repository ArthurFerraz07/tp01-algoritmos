#include "store.h"

using namespace std;

Store getStore(vector<Store> &stores, int id) {
  for(int i = 0; i < stores.size(); i++){
    if(stores[i].id == id){
      return stores[i];
    }
  }
  return Store();
}

// Default constructor
Store::Store(){}

// Constructor
Store::Store(int id_, int index_, int stock_, int x, int y) {
  id = id_;
  index = index_;
  originalStock = stock_;
  localization = Localization(x, y);
  isActive = true;
}

// Add client on clientsPreferred list
void Store::addClient(Client client){

  if(clientsPreferred.empty()){
    clientsPreferred.push_back(client);
  } else {
    std::vector<Client>::iterator it;
    int i = 0;
    int insert = 0;
    for(it = clientsPreferred.begin(); it != clientsPreferred.end(); it++){
      if(clientsPreferred[i].localization.distance(localization) > client.localization.distance(localization) ||
         (clientsPreferred[i].localization.distance(localization) == client.localization.distance(localization) && clientsPreferred[i].ticket() < client.ticket()) ||
         (clientsPreferred[i].localization.distance(localization) == client.localization.distance(localization) && clientsPreferred[i].ticket() == client.ticket() && clientsPreferred[i].id > client.id)){
        insert = 1;
        clientsPreferred.insert(it, client);
        return;
      }
      i++;
    }
    if(insert == 0){
      clientsPreferred.push_back(client);
    }
  }
}

// attempt to schedule a visit to a store
void Store::attemptSchedule(vector<Store> &stores, Client &client){
  if(client.scheduledStoreId == id){
    return;
  }


  bool scheduleClient = false;
  bool switchClient = false;
  bool shouldRemoveWorseClient = false;
  if(hasStock() && client.scheduledStoreId == -1){
    scheduleClient = true;
  } else if (!hasStock() && client.scheduledStoreId == -1){
    for(int i = 0; i < clients.size(); i++){
      if(clients[i].ticket() < client.ticket()){
        scheduleClient = true;
        break;
      }
    }
  } else {
    for(int i = 0; i < clients.size(); i++){
      if(clients[i].localization.distance(localization) > client.localization.distance(localization) ||
        (clients[i].localization.distance(localization) == client.localization.distance(localization) && clients[i].ticket() < client.ticket()) ||
        (clients[i].localization.distance(localization) == client.localization.distance(localization) && clients[i].ticket() == client.ticket() && clients[i].id > client.id)){
        scheduleClient = true;
        break;
      }
    }
    if(scheduleClient && !hasStock()){
      switchClient = true;
    }
    
  }

  if(switchClient){
    Store auxStore = getStore(stores, client.scheduledStoreId);
    int i;
    for(i = 0; i < auxStore.clients.size(); i++){
      if(auxStore.clients[i].id == client.id){
        break;
      }
    }
    client.scheduledStoreId = -1;
    if(i < auxStore.clients.size()){
      auxStore.clients.erase(auxStore.clients.begin() + i);
    }
    // client.print();
    // cout << "auxStore Client IDs: [ ";
    // for (int i = 0; i < auxStore.clients.size(); i++) {
    //   cout << auxStore.clients[i].id << " ";
    // }
    // cout << "]" << endl;
  }

  if(scheduleClient){
    // cout << "scheduleClient " << id << "<->" << client.id << endl;
    client.scheduledStoreId = id;
    clients.push_back(client);

    // cout << "Client IDs: [ ";
    // for (int i = 0; i < clients.size(); i++) {
    //   cout << clients[i].id << " ";
    // }
    // cout << "]" << endl;

    if(originalStock - int(clients.size()) < 0){
      // cout << "!hasStock()" << endl;
      // removeWorseClient();
    }
  }
}

// Print attributes
void Store::print() {
  cout << "Store: " << id << endl;
  cout << "Index: " << id << endl;
  cout << "Stock: " << originalStock << endl;
  cout << "Active: " << isActive << endl;
  cout << "Preferred clients: [ ";
  for(int i = 0; i < clientsPreferred.size(); i++){
    cout << clientsPreferred[i].localization.distance(localization) << "/" << clientsPreferred[i].ticket() << "/" << clientsPreferred[i].id << " ";
  }
  cout << "]" << endl;
  cout << "Client IDs: [ ";
  for (int i = 0; i < clients.size(); i++) {
    cout << clients[i].id << " ";
  }
  cout << "]" << endl;
  localization.print();
  cout << endl;
}

// Push client id to client ids vector
void Store::pushClient(Client client){
  clients.push_back(client);
}

// Remove worseClient 
void Store::removeWorseClient(){
  Client worstClient = Client();
  int worstClientIndex = -1;
  for(int i = 0; i < clients.size(); i++){
    if (i == 0 || clients[i].localization.distance(localization) > worstClient.localization.distance(localization) ||
        (clients[i].localization.distance(localization) == worstClient.localization.distance(localization) && clients[i].ticket() < worstClient.ticket()) ||
        (clients[i].localization.distance(localization) == worstClient.localization.distance(localization) && clients[i].ticket() == worstClient.ticket() && clients[i].id > worstClient.id)){
      worstClient = clients[i];
      worstClientIndex = i;
    }
  }

  if(worstClientIndex != -1){
    // cout << worstClientIndex;

    clients[worstClientIndex].scheduledStoreId = -1;
    clients.erase(clients.begin() + worstClientIndex);
    // cout << "Client IDs: [ ";
    // for (int i = 0; i < clients.size(); i++) {
      // cout << clients[i].id << " ";
    // }
  }
}

// Check if store has stock
bool Store::hasStock() {
  return originalStock - int(clients.size()) > 0;
}
