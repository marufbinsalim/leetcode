#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <optional>

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
    void setTree(TreeNode* node);
    void addLeft(TreeNode* parent, int val);
    void addRight(TreeNode* parent, int val);

    void printTree(TreeNode* node, const std::string& prefix = "", bool isLeft = true);
    void print();

    // NEW: Create tree from array (level-order)
    void fromArray(const std::vector<std::optional<int>>& arr);
};

#endif // TREE_H
