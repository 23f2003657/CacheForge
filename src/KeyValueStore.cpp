#include "KeyValueStore.h"

#include <iostream>

using namespace std;

KeyValueStore::KeyValueStore() {
    cout << "Storage initialized!" << endl;
}
//// Insert or update a key-value pair
void KeyValueStore::set(const string& key, const string& value) {
    storage[key] = value;
}

bool KeyValueStore::get(const string& key, string& value){
    auto it = storage.find(key);

    if (it!=storage.end()){
        value = it->second;
        return true;
    }
    return false;
}

bool KeyValueStore::del(const string& key){
    return storage.erase(key)>0;
}