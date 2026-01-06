#ifndef HEAP2_H
#define HEAP2_H

#include <vector>
#include "File.h"
using namespace std;

struct heap2 {
    int size;
    vector<File*> arr;
    heap2();
    void insert(File* val);
    void check(File* val);
    time_t getMax();
    void deleteMax();
};

#endif
