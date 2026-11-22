#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>

#include "KeyValueStore.h"

using namespace std;

int main() {

    KeyValueStore store;
    string input;

    cout << "CacheForge started!" << endl;

    while (true) {

        cout << "> ";
        
        if(!(getline(cin,input))){
            cout << endl;
            cout << "Shutting down CacheForge.." << endl;
            break;
        }

        istringstream iss(input);

        string operation, key, value;

        if (!(iss >> operation)){
            continue;
        }

        if (operation == "EXIT") {

            cout << "Shutting down CacheForge.." << endl;
            break;
        }

        else if (operation == "SET") {

            iss >> key;
            getline(iss >> ws, value);

            if (key.empty() || value.empty()) {
                cout << "Usage: SET <key> <value>" << endl;
                continue;
            }

            store.set(key, value);

            cout << "OK" << endl;
        }

        else if (operation == "MSET") {

            vector<pair<string, string>> pairs;

            string remaining, segment;

            getline(iss, remaining);

            auto lastChar = remaining.find_last_not_of(" \t\r\n");
            bool invalid = (lastChar == string::npos || remaining[lastChar] == ',');

            istringstream msetStream(remaining);

            while (getline(msetStream, segment, ',')){

                istringstream segmentStream(segment);
                

                if(!(segmentStream >> key)){
                    invalid = true;
                    break;
                }

                if(!getline(segmentStream >> ws, value)|| value.empty()) {
                    invalid = true;
                    break;
                }

                pairs.push_back({key,value});
            }

            if (invalid || pairs.empty()){
                cout << "Usage: MSET <key> <value> [key value ...]" << endl;
                continue;
            }

            for (const auto& p: pairs) {
                store.set(p.first,p.second);
            }

            cout << "OK" << endl;
        }

        else if (operation == "GET") {

            bool firstValue = true;
            bool hasKeys = false;

            while (iss >> key) {

                hasKeys = true;

                if (!firstValue) {
                    cout << ", ";
                }

                if (store.get(key, value)) {
                    cout << value;
                }
                else {
                    cout << "(nil)";
                }

                firstValue = false;
            }

            if (!hasKeys) {
                cout << "Usage: GET <key> [key ...]" << endl;
            }
            else {
                cout << endl;
            }
        }

        else if (operation == "DEL") {

            int deletedCount = 0;
            bool hasKeys = false;

            while (iss >> key) {

                hasKeys = true;

                if (store.del(key)) {
                    deletedCount++;
                }
            }

            if (!hasKeys) {
                cout << "Enter the fucking key" << endl;
            }
            else {
                cout << deletedCount << endl;
            }
        }

        else {
            cout << "Unknown Command" << endl;
        }
    }

    return 0;
}
