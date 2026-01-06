#include "FakeMap.h"

fakemap::fakemap() {
    files.resize(1000, nullptr);
}

void fakemap::put(TreeNode* f, int version) {
    if (files.size() <= version) {
        files.resize(version * 2, nullptr);
    }
    files[version] = f;
}

TreeNode* fakemap::get(int version) {
    if (version < files.size()) {
        return files[version];
    }
    return nullptr;
}
