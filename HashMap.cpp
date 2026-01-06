#include "HashMap.h"

int HashMap::hash(const string& s) const {
    long long hash_value = 0, p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % MOD;
        p_pow = (p_pow * P) % MOD;
    }
    return (int)(hash_value % TABLE_SIZE);
}

void HashMap::put(const string& key, File* value) {
    int idx = hash(key);
    for (auto& entry : table[idx]) {
        if (entry.key == key) {
            entry.value = value;
            return;
        }
    }
    table[idx].emplace_back(key, value);
}

File* HashMap::get(const string& key) {
    int idx = hash(key);
    for (auto& entry : table[idx]) {
        if (entry.key == key) return entry.value;
    }
    return nullptr;
}

bool HashMap::contains(const string& key) {
    int idx = hash(key);
    for (auto& entry : table[idx]) {
        if (entry.key == key) return true;
    }
    return false;
}
