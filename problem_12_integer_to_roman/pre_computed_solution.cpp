#include <iostream>
#include <vector>
class Solution
{
public:
    std::string integerToRoman(int num)
    {
        // 0, 1000, 2000, 3000
        std::string M[] = {"", "M", "MM", "MMM"};
        // 0, 100, 200, 300, 400, 500, 600, 700, 800, 900
        std::string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 0, 10, 20, 30, 40, 50, 60, 70, 80, 90
        std::string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        std::string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return M[num / 1000] + C[(num % 1000) / 100] +
               X[(num % 100) / 10] + I[num % 10];
    }
};

int main()
{
    Solution solution;
    int i = 3749;
    std::cout << solution.integerToRoman(i) << std::endl;
    return 0;
}