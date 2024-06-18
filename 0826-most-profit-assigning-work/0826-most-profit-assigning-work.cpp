class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Combine difficulty and profit into a single list of pairs
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        
        // Sort the jobs based on difficulty
        sort(jobs.begin(), jobs.end());
        
        // Sort the workers based on their ability
        sort(worker.begin(), worker.end());
        
        int maxProfit = 0, totalProfit = 0, i = 0;
        
        // Iterate through each worker
        for (int ability : worker) {
            // Update the max profit the worker can get by doing jobs within their ability
            while (i < jobs.size() && jobs[i].first <= ability) {
                maxProfit = max(maxProfit, jobs[i].second);
                ++i;
            }
            // Add the max profit to the total profit
            totalProfit += maxProfit;
        }
        
        return totalProfit;
    }
};
