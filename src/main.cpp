#include <iostream>

#include <string>
#include <sstream>

#include "KeyValueStore.h"
using namespace std;



int main() {

    KeyValueStore store;
    string input;
    

    cout << "CacheForge started!" << endl;

    while(true){
        cout << "> ";
        getline(cin,input);
        istringstream iss(input);
        string operation, key, value;

        iss >> operation;

        if (operation == "EXIT") {
            cout << "Shutting down CacheForge.." << endl;
            break;
        }
        else if (operation =="SET"){
            iss >> key ;
            getline(iss>>ws,value);

            if (key.empty() || value.empty() ){
                cout << "Usage: SET <key> <value>" << endl;
                continue;
            }

            store.set(key,value);
            
            cout << "OK" << endl;

        }

        else if (operation == "GET"){
            iss >> key;

            if (key.empty()){
                cout << "Usage: GET <key>" << endl;
                continue;
            }
            if (store.get(key,value)){
                cout << value << endl;
            }
            else {
                cout << "NIL" << endl;
            }
        }

        else if (operation =="DEL"){
            iss >> key;

            if (key.empty()){
                cout << "Usage: DEL <key>" << endl;
                continue;
            }
            if (store.del(key)){
                cout << "1" << endl; // 1 if one element was removed
            }
            else {
                cout << "0" << endl; // 0 if the key didn't exist
            }
        }
        else {
            cout << "Unknown Command" << endl;
        }

    }



    return 0;
}