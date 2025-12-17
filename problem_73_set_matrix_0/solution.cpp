#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:

    void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::vector<int> rowsList(matrix.size());
        std::vector<int> columnsList(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    rowsList[i] = true;
                    columnsList[j] = true;
                }
            }
        }

         for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(rowsList[i] || columnsList[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    Solution solution;
    solution.setZeroes(matrix);

    for (auto& row : matrix) {
        for (auto& col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}