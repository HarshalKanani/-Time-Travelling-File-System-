#ifndef FAKEMAP_H
#define FAKEMAP_H

#include <vector>
#include "TreeNode.h"
using namespace std;

struct fakemap {
    vector<TreeNode*> files;
    fakemap();
    void put(TreeNode* f, int version);
    TreeNode* get(int version);
};

#endif
