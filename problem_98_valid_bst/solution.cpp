#include "tree.h"
#include <climits>

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

    // invalid tree
    Tree tree;
    tree.setRoot(5);
    tree.addLeft(tree.root, 1);
    tree.addRight(tree.root, 4);
    tree.addLeft(tree.root->right, 4);
    tree.addRight(tree.root->left, 5);
    tree.addLeft(tree.root->right, 6);
    std::cout << "Tree structure:\n";
    tree.print();
    std::cout << "Is valid BST: " << (isValidBST(tree.root) ? "Yes" : "No") << std::endl;

    Tree validBST;
    validBST.setRoot(5);
    validBST.addLeft(validBST.root, 4);
    validBST.addLeft(validBST.root, 3);
    validBST.addRight(validBST.root, 7);


    std::cout << "Valid BST:\n";
    validBST.print();
    std::cout << "Is valid BST: " << (isValidBST(validBST.root) ? "Yes" : "No") << std::endl;
    return 0;
}
