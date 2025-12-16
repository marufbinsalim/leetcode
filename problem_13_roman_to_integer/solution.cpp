#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<char, int> characterMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int romanToInt(std::string s) {
        int value = 0;
        int lastValue = 0;

        for(int i = (int)s.size() - 1; i >= 0; i--) {
            int currentValue = characterMap[s[i]];
            if(currentValue >= lastValue) value = value + currentValue;
            else value = value - currentValue;
            lastValue = currentValue;
        }
        return value;
    }
};

int main() {
    Solution solution;
    std::string s = "IV";
    std::cout << solution.romanToInt(s) << std::endl;
    return 0;   
}