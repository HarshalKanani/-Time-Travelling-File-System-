#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <ctime>
#include "TreeNode.h"
#include "FakeMap.h"
using namespace std;

struct File {
    TreeNode* root;
    TreeNode* active_version;
    fakemap version_map;
    int ind_in_heap1;
    int ind_in_heap2;
    int total_versions;
    time_t last_updated;
    string name;

    File(string filename);
    void read();
    void insert(string addit);
    void update(string addit);
    void snapshot(string msg);
    void rollback();
    void rollback(int version_id);
    void history();
};

#endif
