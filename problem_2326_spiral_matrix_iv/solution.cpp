#include <iostream>
#include <vector>
#include "../list/list.h"

class Solution
{
public:

    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        std::vector<int> ordered_list;
        std::vector<std::vector<int>> result(m, std::vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(head) {
                    ordered_list.push_back(head->val);
                    head = head->next;
                }
                else {
                    ordered_list.push_back(-1);
                }
            }
        }

        int currentIndex = 0;
        int count = 0;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                result[top][i] = ordered_list[currentIndex++];
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                result[i][right] = ordered_list[currentIndex++];

            }
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    result[bottom][i] = ordered_list[currentIndex++];

                }
                bottom--;
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--){
                    result[i][left] = ordered_list[currentIndex++];
                }
                left++;
            }
        }

        return result;
    }
};
int main()
{
    Solution solution;



    // std::vector<int> list = {3,0,2,6,8,1,7,9,4,2,5,5,0};
    std::vector<int> list = {0, 1, 2};

    List linkedList;
    ListNode* head = linkedList.fromList(list);
    linkedList.setHead(head);
    
    std::vector<std::vector<int>> spiralOrder = solution.spiralMatrix(1, 4, linkedList.head);
    std::cout << "list: " << std::endl;
    linkedList.print();
    std::cout << std::endl;
    std::cout << "spiral Matrix Generated: " << std::endl;
    std::cout << "size : (" << spiralOrder.size() << " x " << spiralOrder[0].size() << ")" << std::endl;
    for (int i = 0; i < spiralOrder.size(); i++)
    {
        for (int j = 0; j < spiralOrder[i].size(); j++)
        {
            std::cout << spiralOrder[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

// 1 →  2  → 3
//           ↓
// 4  → 5    6
// ↑         ↓
// 7  ← 8  ← 9