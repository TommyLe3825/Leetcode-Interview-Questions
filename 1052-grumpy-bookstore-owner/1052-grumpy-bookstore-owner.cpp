#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Step 1: Calculate the initial number of satisfied customers
        int satisfiedCustomers = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                satisfiedCustomers += customers[i];
            }
        }
        
        // Step 2: Calculate the maximum number of additional satisfied customers using sliding window
        int maxAdditionalCustomers = 0;
        int currentAdditionalCustomers = 0;
        
        // Initial window of size `minutes`
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalCustomers += customers[i];
            }
        }
        
        maxAdditionalCustomers = currentAdditionalCustomers;
        
        // Slide the window across the array
        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentAdditionalCustomers += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentAdditionalCustomers -= customers[i - minutes];
            }
            maxAdditionalCustomers = max(maxAdditionalCustomers, currentAdditionalCustomers);
        }
        
        // Step 3: Sum the initial satisfied customers and the maximum additional customers
        return satisfiedCustomers + maxAdditionalCustomers;
    }
};
