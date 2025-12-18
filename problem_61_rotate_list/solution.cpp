#include <iostream>
#include "../list/list.h"


class Solution {
public:

    std::vector<int> nodeVecor;
    std::vector<int> newNodeVector;

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temporary = head;
        while(temporary) {
            nodeVecor.push_back(temporary->val);
            temporary = temporary->next;
        }
        int size = nodeVecor.size();
        if(size == 0) return nullptr;
        int rotate = k % size;
        for(int i = (size - rotate); i < size; i++) {
            newNodeVector.push_back(nodeVecor[i]);
        }
        for(int i = 0; i < (size - rotate); i++) {
           newNodeVector.push_back(nodeVecor[i]);
        }

        ListNode *newHead = new ListNode(newNodeVector[0]);
        ListNode *current = newHead;
        for(int i = 1; i < newNodeVector.size(); i++) {
            current->next = new ListNode(newNodeVector[i]);
            current = current->next;
        }
        return newHead;
    }
};



int main() {
    std::vector<int> list = {1, 2, 3, 4, 5};
    List linkedList;
    ListNode* head = linkedList.fromList(list);
    linkedList.setHead(head);
    std::cout << "Before Rotation : ";
    linkedList.print();
    std::cout << std::endl;
    for(int i = 0; i < 6; i++) {
        Solution solution;
        ListNode* result = solution.rotateRight(head, i);
        linkedList.setHead(result);
        std::cout << "After " << i << "th Rotation : ";
        linkedList.print();
        std::cout << std::endl;
    }
}

// 1 2 3 4 5
// 5 1 2 3 4 -> 1 
// 4 5 1 2 3 -> 2
// 3 4 5 1 2 -> 3
// 2 3 4 5 1 -> 4
// 1 2 3 4 5 -> 5
// 5 1 2 3 4 -> 1