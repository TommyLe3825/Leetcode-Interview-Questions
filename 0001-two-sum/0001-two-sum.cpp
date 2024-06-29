#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // Create a hash map to store the indices of the elements
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // Calculate the complement
            if (num_map.find(complement) != num_map.end()) {
                // If the complement exists in the map, return the indices
                return {num_map[complement], i};
            }
            // Otherwise, add the current element and its index to the map
            num_map[nums[i]] = i;
        }
        return {}; // In case no solution is found, though the problem guarantees one
    }
};
