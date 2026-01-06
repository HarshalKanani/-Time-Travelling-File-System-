#include <iostream>
#include <sstream>
#include "Heap1.h"
#include "Heap2.h"
#include "HashMap.h"
using namespace std;

int main(){
    heap1 Heap1;
    heap2 Heap2;
    HashMap fileMap;
    while (true) {
        string line;
        cout << "Enter command: ";
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        std::istringstream ss(line);
        string command;
        ss >> command;

        if (command == "CREATE") {
            string filename;
            getline(ss, filename);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (fileMap.contains(filename)) {
                cout << "File already exists!" << endl;
                continue;
            }
            File* newFile = new File(filename);
            fileMap.put(filename, newFile);
            Heap1.insert(newFile);
            Heap2.insert(newFile);
        }
        else if (command == "READ") {
            string filename;
            getline(ss, filename);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            fileMap.get(filename)->read();
            Heap1.check(fileMap.get(filename));
            Heap2.check(fileMap.get(filename));
        }
        else if (command == "UPDATE") {
            string filename, addit;
            ss >> std::ws;
            getline(ss, filename, ' ');
            getline(ss, addit);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!addit.empty() && addit[0] == ' ') addit = addit.substr(1);
            if (addit.size() < 2 || addit.front() != '"' || addit.back() != '"') {
                cout << "Error: Content must be enclosed in double quotes ("")." << endl;
                continue;
            }
            addit = addit.substr(1, addit.size() - 2);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            fileMap.get(filename)->update(addit);
            Heap1.check(fileMap.get(filename));
            Heap2.check(fileMap.get(filename));
        }
        else if (command == "INSERT") {
            string filename, addit;
            ss >> std::ws;
            getline(ss, filename, ' ');
            getline(ss, addit);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!addit.empty() && addit[0] == ' ') addit = addit.substr(1);
            if (addit.size() < 2 || addit.front() != '"' || addit.back() != '"') {
                cout << "Error: Content must be enclosed in double quotes ("")." << endl;
                continue;
            }
            addit = addit.substr(1, addit.size() - 2);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            fileMap.get(filename)->insert(addit);
            Heap1.check(fileMap.get(filename));
            Heap2.check(fileMap.get(filename));
        }
        else if (command == "SNAPSHOT") {
            string filename, message;
            ss >> std::ws;
            getline(ss, filename, ' ');
            getline(ss, message);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!message.empty() && message[0] == ' ') message = message.substr(1);
            if (message.size() < 2 || message.front() != '"' || message.back() != '"') {
                cout << "Error: Message must be enclosed in double quotes ("")." << endl;
                continue;
            }
            message = message.substr(1, message.size() - 2);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            fileMap.get(filename)->snapshot(message);
            Heap1.check(fileMap.get(filename));
            Heap2.check(fileMap.get(filename));
        }
        else if (command == "ROLLBACK") {
            string filename;
            int version = -1;
            ss >> std::ws;
            getline(ss, filename, ' ');
            ss >> version;
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            if (version == -1)
                fileMap.get(filename)->rollback();
            else
                fileMap.get(filename)->rollback(version);
            Heap1.check(fileMap.get(filename));
            Heap2.check(fileMap.get(filename));
        }
        else if (command == "EXIT") {
            break;
        }
        else if (command == "RECENT_FILES") {
            int k;
            ss >> k;
            vector<File*> temp;
            for (int i = 0; i < k; i++) {
                if (Heap2.size == 0) break;
                cout << Heap2.arr[0]->name << " " << ctime(&Heap2.arr[0]->last_updated);
                temp.push_back(Heap2.arr[0]);
                Heap2.deleteMax();
            }
            for (File* f : temp) {
                Heap2.insert(f);
            }
            temp.clear();
        }
        else if (command == "MOST_VERSIONS") {
            int k;
            ss >> k;
            vector<File*> temp;
            for (int i = 0; i < k; i++) {
                if (Heap1.size == 0) break;
                cout << Heap1.arr[0]->name << " " << Heap1.arr[0]->total_versions << endl;
                temp.push_back(Heap1.arr[0]);
                Heap1.deleteMax();
            }
            for (File* f : temp) {
                Heap1.insert(f);
            }
            temp.clear();
        }
        else if (command == "HISTORY") {
            string filename;
            getline(ss, filename);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            fileMap.get(filename)->history();
        }
        else if (command == "VERSIONS") {
            string filename;
            getline(ss, filename);
            if (!filename.empty() && filename[0] == ' ') filename = filename.substr(1);
            if (!fileMap.contains(filename)) {
                cout << "File not found!" << endl;
                continue;
            }
            cout << "Total versions: " << fileMap.get(filename)->total_versions << endl;
        }
        else {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}
