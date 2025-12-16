#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Tree {
public:
    TreeNode* root = nullptr;

    Tree() = default;

    void setRoot(int val);
    void addLeft(TreeNode* parent, int val);
    void addRight(TreeNode* parent, int val);

    void printTree(TreeNode* node, const std::string& prefix = "", bool isLeft = true);
    void print();
};

#endif // TREE_H
