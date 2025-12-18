#include "list.h"

void List::print()
{
    ListNode *current = head;
    while (current)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void List::setHead(ListNode *node)
{
    this->head = node;
}

ListNode *List::fromList(const std::vector<int> &list)
{
    if (list.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(list[0]);
    ListNode *current = head;
    for (int i = 1; i < list.size(); i++)
    {
        current->next = new ListNode(list[i]);
        current = current->next;
    }
    return head;
}
