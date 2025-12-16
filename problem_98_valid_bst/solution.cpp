#include "../tree/tree.h"
#include <optional>
#include <vector>
#include <climits>
#include <iostream>

bool isValidBST(TreeNode* root, long long min, long long max) {
    if(root == nullptr) return true;
    if(root->val <= min || root->val >= max) return false;
    if(root->left != nullptr && root->left->val >= root->val) return false;
    if(root->right != nullptr && root->right->val <= root->val) return false;
    return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
}


bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    // Invalid tree: [5,1,4,5,?,6] (LeetCode-style)
    Tree tree;
    std::vector<std::optional<int>> arr1 = {5, 1, 4, 5, std::nullopt, 6};
    tree.fromArray(arr1);

    std::cout << "Tree structure:\n";
    tree.print();
    std::cout << "Is valid BST: " << (isValidBST(tree.root) ? "Yes" : "No") << std::endl;

    // Valid BST: [5,4,7,3]
    Tree validBST;
    std::vector<std::optional<int>> arr2 = {5, 4, 7, 3};
    validBST.fromArray(arr2);

    std::cout << "\nValid BST:\n";
    validBST.print();
    std::cout << "Is valid BST: " << (isValidBST(validBST.root) ? "Yes" : "No") << std::endl;

    return 0;
}
