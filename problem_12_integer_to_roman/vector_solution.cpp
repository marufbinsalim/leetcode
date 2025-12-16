#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<std::pair<int, std::string>> pairs = {
        { 1000, "M" },
        { 900, "CM" },
        { 500, "D" },
        { 400, "CD" },
        { 100, "C" },
        { 90, "XC" },
        { 50, "L" },
        { 40, "XL" },
        { 10, "X" },
        { 9, "IX" },
        { 5, "V" },
        { 4, "IV" },    
        { 1, "I" }
    };

    std::string integerToRoman(int num) {

        std::string roman = "";
        while (num)
        {
            for(auto [key, value] : pairs) {
                std::cout << key << " " << value << std::endl;
                if(num >= key) {
                    roman += value;
                    num = num - key;
                    break;
                }
            }
        }

        return roman;
    }
};

int main() {
    Solution solution;
    int i = 3749;
    std::cout << solution.integerToRoman(i) << std::endl;
    return 0;   
}