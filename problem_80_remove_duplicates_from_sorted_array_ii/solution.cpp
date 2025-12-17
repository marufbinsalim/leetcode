#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums){
        int read = 2;
        int write = 2;
        while(read < nums.size()){
            if(nums[read] != nums[write-2]) {
                nums[write] = nums[read];
                write++;
            }
            read++;
        }
        return std::min(write, (int)nums.size());
    }
};

int main()
{

    Solution solution;
    std::vector<int> array = {1, 1, 1, 3, 4, 4, 4, 6, 12, 12, 12, 25};
    std::cout << "Original array: " << std::endl;
    for (int i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\nremoved duplicates: " << std::endl;
    const int n = solution.removeDuplicates(array);
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
