#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <vector>
#include "File.h"
using namespace std;

struct HashMap {
    static const int TABLE_SIZE = 10009;
    static const int P = 31;
    static const int MOD = 1000000009; // 1e9+9

    struct Entry {
        string key;
        File* value;
        Entry(const string& k, File* v) : key(k), value(v) {}
    };
    vector<Entry> table[TABLE_SIZE];

    int hash(const string& s) const;
    void put(const string& key, File* value);
    File* get(const string& key);
    bool contains(const string& key);
};

#endif
