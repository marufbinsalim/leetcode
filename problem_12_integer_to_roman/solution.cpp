#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::unordered_map<int, char> characterMap = {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000, 'M'}
    };

    std::string integerToRoman(int num) {

        std::string roman = "";
        while (num)
        {
            if(num >= 1000) 
            {
                roman += characterMap[1000];
                num = num - 1000;
                continue;
            }
            else if(num >= 900) 
            {
                roman += characterMap[100];
                roman += characterMap[1000];
                num = num - 900;
                continue;
            }
            else if(num >= 500) 
            {
                roman += characterMap[500];
                num = num - 500;
                continue;
            }
            else if(num >= 400) 
            {
                roman += characterMap[100];
                roman += characterMap[500];
                num = num - 400;
                continue;
            }
            else if(num >= 100) 
            {
                roman += characterMap[100];
                num = num - 100;
                continue;
            }
            else if(num >= 90)
            {
                roman += characterMap[10];
                roman += characterMap[100];
                num = num - 90;
                continue;
            }
            else if(num >= 50) 
            {
                roman += characterMap[50];
                num = num - 50;
                continue;
            }
            else if(num >= 40) 
            {
                roman += characterMap[10];
                roman += characterMap[50];
                num = num - 40;
                continue;
            }
            else if(num >= 10) 
            {
                roman += characterMap[10];
                num = num - 10;
                continue;
            }
            else if(num >= 9) 
            {
                roman += characterMap[1];
                roman += characterMap[10];
                num = num - 9;
                continue;
            }
            else if(num >= 5) 
            {
                roman += characterMap[5];
                num = num - 5;
                continue;
            }
            else if(num >= 4) 
            {
                roman += characterMap[1];
                roman += characterMap[5];
                num = num - 4;
                continue;
            }
            else if(num >= 1) 
            {
                roman += characterMap[1];
                num = num - 1;
                continue;
            }
            num = 0;
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