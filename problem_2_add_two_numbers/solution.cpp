#include <iostream>
#include <vector>
#include <algorithm>
#include "../list/list.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head_1 = l1;
        ListNode *head_2 = l2;
        ListNode *head = nullptr;
        ListNode *current = head;
        int carry = 0;
        while (head_1 || head_2 || carry)
        {
            int bit_1 = head_1 ? head_1->val : 0;
            int bit_2 = head_2 ? head_2->val : 0;
            int sum = bit_1 + bit_2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            if (!current) {
                current = new ListNode(sum);
                head = current;
            }
            else {
                current->next = new ListNode(sum);
                current = current->next;
            }

            if (head_1)
                head_1 = head_1->next;
            if (head_2)
                head_2 = head_2->next;

            if (!head_1 && !head_2)
            {
                if (carry)
                {
                    if (!current)
                        current = new ListNode(carry);
                    else
                        current->next = new ListNode(carry);
                }
                break;
            }
        }

        return head;
    }
};
int main()
{
    Solution solution;
    std::vector<int> l1 = {1, 8, 6, 2, 5, 4, 8, 3, 1};
    std::vector<int> l2 = {1, 8, 6, 2, 5, 4, 8, 3, 1};

    List linkedList1;
    ListNode *head1 = linkedList1.fromList(l1);
    linkedList1.setHead(head1);
    linkedList1.print();
    std::cout << std::endl;
    List linkedList2;
    ListNode *head2 = linkedList2.fromList(l2);
    linkedList2.setHead(head2);
    linkedList2.print();
    std::cout << std::endl;

    List result;
    ListNode *resultHead = solution.addTwoNumbers(linkedList1.head, linkedList2.head);
    result.setHead(resultHead);
    std::cout << "Result : ";
    result.print();
    return 0;
}