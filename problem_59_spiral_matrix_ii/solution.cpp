#include <iostream>
#include <vector>

class Solution
{
public:

    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int value = 1;
        while(top <= bottom && left <= right) {
            for(int i = left; i <= right; i++) {
                matrix[top][i] = value;
                value++;
            }
            top++;

            for(int i = top; i <= bottom; i++) {
                matrix[i][right] = value;
                value++;
            }
            right--;

            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    matrix[bottom][i] = value;
                    value++;
                }
                bottom--;
            }

            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    matrix[i][left] = value;
                    value++;
                }
                left++;
            }

        }
        return matrix;
    }
};
int main()
{
    Solution solution;

    std::vector<std::vector<int>> spiralOrder = solution.generateMatrix(3);
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