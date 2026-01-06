#include "TreeNode.h"

TreeNode::TreeNode(int vid, const string& cont, const string& msg, time_t ctime, time_t stime, TreeNode* par) {
    version_id = vid;
    content = cont;
    message = msg;
    created_timestamp = ctime;
    snapshot_timestamp = stime;
    parent = par;
    children.clear();
}
