#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        std::unordered_map<int, int> count; //key is the current element in nums, and value is the count
        for (int num : nums) { //count is collected for each num
            count[num]++;
        }

        int duplicate = -1, missing = -1; //found out that -1 is used to show there are no valid values yet
        for (int i = 1; i <= nums.size(); i++) {
            if (count[i] == 2) { //If the certain key has a value of 2, it means that it popped up twice
                duplicate = i;
            } else if (count[i] == 0) { //Since the one that is missing won't be in the vector, it will have a count of 0
                missing = i; //This means as it is looping, whatever number it is currently at must be missing based on the count of 0
            }
        }

        return {duplicate, missing};
    }
};