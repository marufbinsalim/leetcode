#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:

    std::string RleEncoding(int n) {
        std::string RLE = "";
        int reversed = 0;
        while(n) {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        int previous = -1;
        int count = 1;
        while (reversed)
        {
            int digit = reversed % 10;
            if(digit == previous) count++;
            else if(previous != -1) {
                RLE += std::to_string(count) + std::to_string(previous);
                count = 1;
            }
            previous = digit;
            reversed /= 10;
        }
        if(previous != -1) {
            RLE += std::to_string(count) + std::to_string(previous);
        }
        return RLE;
    }
    std::string countAndSay(int n) {
        int number = n;
        if(number != 1) number--;
        if(n == 1) return RleEncoding(n);
        return RleEncoding(std::stoi(countAndSay(n-1)));
    }
};
int main()
{
    Solution solution;
    for(int i = 1; i <= 5; i++) {
        std::cout << "nth RLE Encoding: " << solution.countAndSay(i) << std::endl;
    }
    return 0;
}