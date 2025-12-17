#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int first = 0;
        int second = height.size() - 1;
        int area = std::min(height[first], height[second]) * (second - first);
        while (first < second)
        {
            if (height[first] < height[second]) first++;
            else second--;
            const int currentArea = std::min(height[first], height[second]) * (second - first);
            if (currentArea > area) area = currentArea;
        }
        return area;
    }
};
int main()
{
    Solution solution;
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << " maximu area is : " << solution.maxArea(height) << std::endl;
    return 0;
}