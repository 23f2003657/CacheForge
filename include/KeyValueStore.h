#pragma once

#include <string>
#include <unordered_map>


class KeyValueStore {

private:
    std::unordered_map<std::string,std::string> storage;
public:
    KeyValueStore();
    void set(const std::string& key, std::string& value);
    bool get(const std::string& key, std::string& value);
    bool del(const std::string& key);
};