class Solution {
public:
    int minIncrementForUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int moves = 0;
        //Iterate through the sorted array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is not greater than the previous element
            if (nums[i] <= nums[i - 1]) {
                //Calculate the number of increments needed
                int increment = nums[i - 1] + 1 - nums[i];
                //Add the increments to the moves counter
                moves += increment;
                //Update the current element to its new unique value
                nums[i] = nums[i - 1] + 1;
            }
        }
        return moves;
    }
};
