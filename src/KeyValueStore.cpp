#include "KeyValueStore.h"

#include <iostream>

using namespace std;

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