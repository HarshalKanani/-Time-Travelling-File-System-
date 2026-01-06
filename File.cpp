#include "File.h"
#include <iostream>
#include <algorithm>

File::File(string filename) {
    name = filename;
    root = new TreeNode(0, "", "Initial version", time(nullptr), time(nullptr), NULL);
    root->snapshot = true;
    active_version = root;
    version_map.put(root, 0);
    total_versions = 1;
    last_updated = time(nullptr);
}

void File::read() {
    cout << active_version->content << endl;
}

void File::insert(string addit) {
    if (active_version->snapshot) {
        TreeNode* new_node = new TreeNode(total_versions, active_version->content + addit, "", time(nullptr), 0, active_version);
        active_version->children.push_back(new_node);
        active_version = new_node;
        version_map.put(active_version, active_version->version_id);
        total_versions++;
    } else {
        active_version->content += addit;
    }
    last_updated = time(nullptr);
}

void File::update(string addit) {
    if (active_version->snapshot) {
        TreeNode* new_node = new TreeNode(total_versions, addit, "", time(nullptr), 0, active_version);
        active_version->children.push_back(new_node);
        active_version = new_node;
        version_map.put(active_version, active_version->version_id);
        total_versions++;
    } else {
        active_version->content = addit;
    }
    last_updated = time(nullptr);
}

void File::snapshot(string msg) {
    if (!active_version->snapshot) {
        active_version->snapshot = true;
        active_version->message = msg;
        active_version->snapshot_timestamp = time(nullptr);
    }
}

void File::rollback() {
    if (active_version->parent != nullptr) {
        active_version = active_version->parent;
    } else {
        cout << "Already at root version!" << endl;
    }
}

void File::rollback(int version_id) {
    TreeNode* node = version_map.get(version_id);
    if (node != nullptr) {
        active_version = node;
    } else {
        cout << "Version ID not found!" << endl;
    }
}

void File::history() {
    TreeNode* curr = active_version;
    vector<TreeNode*> hist;
    while (curr != nullptr) {
        hist.push_back(curr);
        curr = curr->parent;
    }
    reverse(hist.begin(), hist.end());
    for (auto& node : hist) {
        cout << "Version ID: " << node->version_id << endl;
        cout << "Message: " << node->message << endl;
        cout << "Created Timestamp: " << ctime(&node->created_timestamp);
        cout << "Snapshot Timestamp: " << ctime(&node->snapshot_timestamp);
    }
}
