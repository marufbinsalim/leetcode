#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

class Solution
{
public:
    int dp[101][101];
    std::vector<std::vector<int>> obstacleGrid;
    int traverse(int y, int x, int ty, int tx)
    {
        if (x == tx - 1 && y == ty - 1)
        return 1;
        if (x >= tx)
        return 0;
        if (y >= ty)
        return 0;

        if (obstacleGrid[y][x] == 1)
            return 0;

        if (dp[y][x] != -1)
            return dp[y][x];

        dp[y+1][x] = traverse(y + 1, x, ty, tx);
        dp[y][x+1] = traverse(y, x + 1, ty, tx);
        
        return dp[y+1][x] + dp[y][x+1];
    }

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        this->obstacleGrid = obstacleGrid;
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return traverse(0, 0, m, n);
        
    }
};

int main()
{

    Solution solution;
    std::vector<std::vector<int>> obstacleGrid = {
      {0, 0},
      {0, 1}
    };
    std::cout << solution.uniquePathsWithObstacles(obstacleGrid) << std::endl;
    return 0;
}