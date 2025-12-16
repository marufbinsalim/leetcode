#include "tree.h"

// Set the root node
void Tree::setRoot(int val) {
    if (!root) root = new TreeNode(val);
}

// Add node to the left
void Tree::addLeft(TreeNode* parent, int val) {
    if (!parent) return;
    parent->left = new TreeNode(val);
}

// Add node to the right
void Tree::addRight(TreeNode* parent, int val) {
    if (!parent) return;
    parent->right = new TreeNode(val);
}

// Pretty print
void Tree::printTree(TreeNode* node, const std::string& prefix, bool isLeft) {
    if (!node) return;

    if (node->right) printTree(node->right, prefix + (isLeft ? "│   " : "    "), false);

    std::cout << prefix << (isLeft ? "└── " : "┌── ") << node->val << "\n";

    if (node->left) printTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
}

void Tree::print() {
    printTree(root);
}
