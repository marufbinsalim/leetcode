#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <optional>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class List {
public:
    ListNode* head = nullptr;

    List() = default;
    void print();
    void setHead(ListNode* node);
    ListNode* fromList(const std::vector<int>& list);
};

#endif // TREE_H
