#ifndef HEAP1_H
#define HEAP1_H

#include <vector>
#include "File.h"
using namespace std;

struct heap1 {
    int size;
    vector<File*> arr;
    heap1();
    void insert(File* val);
    void check(File* val);
    int getMax();
    void deleteMax();
};

#endif
