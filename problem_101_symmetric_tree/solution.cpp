#include "../tree/tree.h"
#include <optional>
#include <vector>
#include <climits>
#include <iostream>


bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(left && !right) return false;
        if(right && !left) return false;
        if(left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }

int main() {

    Tree tree;
    // [1,2,2,3,4,4,3]
    std::vector<std::optional<int>> treeArray = {1, 2, 2, 3, 4, 4, 3};
    tree.fromArray(treeArray);

    std::cout << "Tree structure:\n"; // an invalid bst with 2 misplaced nodes
    tree.print();
    std::cout << "Is symmetric: " << (isSymmetric(tree.root) ? "Yes" : "No") << std::endl;
    return 0;
}
