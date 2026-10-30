#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class KeyValueStore {

private:
    unordered_map<string,string> storage;
public:
    // Constructor
    KeyValueStore(){
        cout << "Storage Initialised" << endl;
    }

    // inserting or updating a key-value pair
    void set(const string& key, const string& value){
        storage[key] = value;
    }

    //retrieving a value
    bool get(const string& key, string& value){
        auto it = storage.find(key);

        if (it != storage.end()){
            value = it->second;
            return true;
        }

        return false;
    }

    // deleting a key value pair
    bool del(const string& key){
        return storage.erase(key) > 0; // erase() returns the number of elements removed.
    }

};

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
            iss >> key >> value;

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