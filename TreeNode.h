#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct TreeNode {
    int version_id;
    string content;
    string message;
    time_t created_timestamp;
    time_t snapshot_timestamp;
    TreeNode* parent;
    vector<TreeNode*> children;
    bool snapshot;

    TreeNode(int vid, const string& cont, const string& msg, time_t ctime, time_t stime, TreeNode* par);
};

#endif
