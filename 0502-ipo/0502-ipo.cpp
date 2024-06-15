#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        //Sort projects based on the capital required to start them
        std::sort(projects.begin(), projects.end());
        
        //Max-heap to store the profits of the projects that can be started
        std::priority_queue<int> maxHeap;
        
        int projectIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            //Add all projects that can be started with the current capital
            while (projectIndex < n && projects[projectIndex].first <= w) {
                maxHeap.push(projects[projectIndex].second);
                ++projectIndex;
            }
            
            //If no project can be started, break the loop
            if (maxHeap.empty()) {
                break;
            }
            
            //Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};
