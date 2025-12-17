#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string RleEncoding(std::string n)
    {
        std::string RLE = "";
        char previous = 'x';
        int count = 1;
        for (int i = 0; i < n.size(); i++)
        {
                char current = n[i];
                if (current == previous)
                    count++;
                else if (previous != 'x')
                {
                    RLE += std::to_string(count) + previous;
                    count = 1;
                }
                previous = current;
        }
        if (previous != 'x')
        {
            RLE += std::to_string(count) + previous;
        }
        return RLE;
    }
    std::string countAndSay(int n)
    {
        if (n == 1) return "1";
        return RleEncoding(countAndSay(n - 1));
    }
};
int main()
{
    Solution solution;
    std::cout << "112223333 RLE Encoding: " <<     solution.RleEncoding("112223333") << std::endl;
    for (int i = 1; i <= 30; i++)
    {
        std::cout << i << "th RLE Encoding: " << solution.countAndSay(i) << std::endl;
    }
    return 0;
}