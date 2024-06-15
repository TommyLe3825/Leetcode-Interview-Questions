#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        //k = maximum number of projects that can be completed
        //w = inital capital
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        
        for (int i = 0; i < n; ++i) {
            //Paring the capital and profit elements togehter
            projects[i] = {capital[i], profits[i]};
        }
        
        //Sort projects based on the capital required to start them
        std::sort(projects.begin(), projects.end());
        
        //Max-heap to store the profits of the projects that can be started
        //maxHeap stores the highest profit on top always among other feasible projects
        std::priority_queue<int> maxHeap;
        
        //It will be used to track the current position in the sorted list of projectts
        int projectIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            //Add all projects that can be started with the current capital
            //ProjectIndex < n makes sure the projectIndex is within the bounds of profits.size
            //Projects[projectIndex].first... checks if the current capital is <= w
            while (projectIndex < n && projects[projectIndex].first <= w) {
                //Pushes current profit to maxHeap
                maxHeap.push(projects[projectIndex].second); 
                //Updates the index immediately
                ++projectIndex;
            }
            
            //If no project can be started, break the loop
            if (maxHeap.empty()) {
                break;
            }
            
            //Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop(); //remove it after adding the profit to w
        }
        
        return w;
    }
};
