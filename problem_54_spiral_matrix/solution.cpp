#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        int numberOfRows = matrix.size();
        int numberOfColumns = matrix[0].size();
        std::vector<int> spiralOrder(numberOfRows * numberOfColumns, 0);
        
        int top = 0;
        int left = 0;
        int right = numberOfColumns - 1;
        int bottom = numberOfRows - 1;
        int index = 0;

        while (top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++) {
                spiralOrder[index++] = matrix[top][i];
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                spiralOrder[index++] = matrix[i][right];
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    spiralOrder[index++] = matrix[bottom][i];
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    spiralOrder[index++] = matrix[i][left];
                }
                left++;
            }
        }
        return spiralOrder;

    }
};
int main()
{
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    std::vector<int> spiralOrder = solution.spiralOrder(matrix);
    std::cout << "spiralOrder: " << std::endl;
    for (int i = 0; i < spiralOrder.size(); i++)
    {
        std::cout << spiralOrder[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

// 1 →  2  → 3
//           ↓
// 4  → 5    6
// ↑         ↓
// 7  ← 8  ← 9