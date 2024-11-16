#include <vector> //to use std::vector class for dynamic arrays
using namespace std; //won't need to using prefix std:: 

class Solution { //remember class is like a blueprint
public:
    vector<int> resultsArray(vector<int>& nums, int k) { //nums is a reference, k-> size 
        vector<int> results;//array of integers 
        int n = nums.size();
        
        // Iterate over all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            bool isConsecutive = true;
            
            // Check if the subarray is consecutive and sorted
            for (int j = i; j < i + k - 1; j++) { 
                if (nums[j] + 1 != nums[j + 1]) { 
                    isConsecutive = false;
                    break;
                }
            }
            
            // Add the result based on the check
            if (isConsecutive) {
                results.push_back(nums[i + k - 1]); // Max element (last element of subarray)
            } else {
                results.push_back(-1);
            }
        }
        
        return results;
    }
};
