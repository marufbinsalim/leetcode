#include "tree.h"

void Tree::setRoot(int val) {
    if (!root) root = new TreeNode(val);
}

void Tree::addLeft(TreeNode* parent, int val) {
    if (!parent) return;
    parent->left = new TreeNode(val);
}

void Tree::addRight(TreeNode* parent, int val) {
    if (!parent) return;
    parent->right = new TreeNode(val);
}

void Tree::printTree(TreeNode* node, const std::string& prefix, bool isLeft) {
    if (!node) return;

    if (node->right) printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);

    std::cout << prefix << (isLeft ? "└── " : "┌── ") << node->val << "\n";

    if (node->left) printTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
}

void Tree::print() {
    printTree(root);
}

// Convert array to tree
void Tree::fromArray(const std::vector<std::optional<int>>& arr) {
    if (arr.empty() || !arr[0].has_value()) {
        root = nullptr;
        return;
    }

    root = new TreeNode(arr[0].value());
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i].has_value()) {
            node->left = new TreeNode(arr[i].value());
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i].has_value()) {
            node->right = new TreeNode(arr[i].value());
            q.push(node->right);
        }
        i++;
    }
}
