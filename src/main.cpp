#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

int main() {
    
    unordered_map<string,string> storage;
    
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
            iss >> key >> value;

            if (key.empty() || value.empty() ){
                cout << "Usage: SET <key> <value>" << endl;
                continue;
            }

            storage[key] = value;
            cout << "OK" << endl;

        }

        else if (operation == "GET"){
            iss >> key;

            if (key.empty()){
                cout << "Usage: GET <key>" << endl;
                continue;
            }
            if (storage.find(key)!= storage.end()){
                cout << storage[key] << endl;
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
            if (storage.erase(key)){
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