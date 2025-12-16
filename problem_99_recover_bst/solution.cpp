#include "../tree/tree.h"
#include <optional>
#include <vector>
#include <climits>
#include <iostream>


void recover(TreeNode* root, TreeNode*& previous, TreeNode*& misplaced_1, TreeNode*& misplaced_2) {
   if(!root) return;
   recover(root->left, previous, misplaced_1, misplaced_2);

   if(previous && root->val <= previous->val) {
       if(!misplaced_1) {
           misplaced_1 = previous;
           misplaced_2 = root;
       }
       else {
           misplaced_2 = root;
       }
   }
   previous = root;
   recover(root->right, previous, misplaced_1, misplaced_2);
}

TreeNode* recoverTree(TreeNode* root) {
    TreeNode* previous = nullptr;
    TreeNode* misplaced_1 = nullptr;
    TreeNode* misplaced_2 = nullptr;
    recover(root, previous, misplaced_1, misplaced_2);
    if(misplaced_1 && misplaced_2) {
        std::swap(misplaced_1->val, misplaced_2->val);
    }
    return root;
}

int main() {

    Tree tree;
    std::vector<std::optional<int>> treeArray = {1, 3, std::nullopt, std::nullopt, 2};
    tree.fromArray(treeArray);

    std::cout << "Tree structure:\n"; // an invalid bst with 2 misplaced nodes
    tree.print();
    tree.setTree(recoverTree(tree.root));
    std::cout << "Recovered tree:\n";
    tree.print();
    return 0;
}
