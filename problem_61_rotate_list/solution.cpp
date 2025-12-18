#include <iostream>
#include <vector>
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* arrayToList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}




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
    int list[] = {1, 2, 3, 4, 5};
    int n = sizeof(list) / sizeof(list[0]);
    ListNode* head = arrayToList(list, n);


    std::cout << "Before Rotation : ";
    ListNode* temporary = head;
    while(temporary) {
        std::cout << temporary->val << " ";
        temporary = temporary->next;
    }
    std::cout << std::endl;

    for(int i = 0; i < 6; i++) {
        Solution solution;
        temporary = solution.rotateRight(head, i);
        std::cout << "After Rotation : ";
        while(temporary) {
            std::cout << temporary->val << " ";
            temporary = temporary->next;
        }
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