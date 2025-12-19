#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>

class Solution
{
public:
    int dp[101][101];
    int traverse(int y, int x, int ty, int tx)
    {
        if (x == tx - 1 && y == ty - 1)
        return 1;
        if (x >= tx)
        return 0;
        if (y >= ty)
        return 0;

        if (dp[y][x] != -1)
            return dp[y][x];

        dp[y+1][x] = traverse(y + 1, x, ty, tx);
        dp[y][x+1] = traverse(y, x + 1, ty, tx);
        
        return dp[y+1][x] + dp[y][x+1];
    }
    int uniquePaths(int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return traverse(0, 0, m, n);
    }
};

int main()
{
    int m = 3;
    int n = 7;
    Solution solution;
    std::cout << solution.uniquePaths(m, n) << std::endl;
    return 0;
}