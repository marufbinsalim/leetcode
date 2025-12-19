#include <iostream>
#include <vector>


enum Direction {
    DECREASING = -1,
    INCREASING = 1
};

class Solution
{
public:
    std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        std::vector<std::vector<int>> matrixCoordinates;
        auto isInRange = [&](int index, int min, int max)
        {
            return index >= min && index < max;
        };
        int x = cStart;
        int y = rStart;
        int elementCount = 0;
        int maxElements = rows * cols;
        Direction direction = Direction::INCREASING;
        int incrementBy = 0;
        bool isRunning = true;
        while (isRunning)
        {
            int signedIncrement = incrementBy * direction;

            const int targetX = x + signedIncrement;

            if(direction == 1) {
                for (x; x <= targetX; x++)
                {
                    if (isInRange(x, 0, cols) && isInRange(y, 0, rows))
                    {
                        ++elementCount;
                        matrixCoordinates.push_back({y, x});
                        if(elementCount == maxElements) {
                            isRunning = false;
                            break;;
                        }
                    }
                }
            }
            else if(direction == -1) {
                for (x; x >= targetX; x--)
                {
                    if (isInRange(x, 0, cols) && isInRange(y, 0, rows))
                    {
                        ++elementCount;
                        matrixCoordinates.push_back({y, x});
                        if(elementCount == maxElements) {
                            isRunning = false;
                            break;;
                        }
                    }
                }
            }
            if(isRunning == false) break;

            const int targetY = y + signedIncrement;

            if(direction == 1) {
                for (y; y <= targetY; y++)
                {
                    if (isInRange(x, 0, cols) && isInRange(y, 0, rows))
                    {
                        ++elementCount;
                        matrixCoordinates.push_back({y, x});
                        if(elementCount == maxElements) {
                            isRunning = false;
                            break;;
                        }
                    }
                }
            }
            else if(direction == -1) {
                for (y; y >= targetY; y--)
                {
                    if (isInRange(x, 0, cols) && isInRange(y, 0, rows))
                    {
                        ++elementCount;
                        matrixCoordinates.push_back({y, x});
                        if(elementCount == maxElements) {
                            isRunning = false;
                            break;;
                        }
                    }
                }
            }

            direction = direction == Direction::INCREASING ? Direction::DECREASING : Direction::INCREASING;
            incrementBy = incrementBy + 1;
        }
        return matrixCoordinates;
    }
};
int main()
{
    Solution solution;

    std::vector<std::vector<int>> spiralOrder = solution.spiralMatrixIII(5, 6, 1, 4);
    std::cout << "spiral Matrix Generated (coordinates of visit): " << std::endl;
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