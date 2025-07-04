class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size() , i = 0;
        long long time = 0;

        for(int i = 0 ; i < n ; i++)
            tasks[i].push_back(i);

        sort(tasks.begin() , tasks.end());
        priority_queue <pair<int,int>> pq;
        vector <int> ans;

        while(not pq.empty() or i < n){
            while(i < n and tasks[i][0] <= time)
                pq.push({-tasks[i][1] , -tasks[i][2]}) , i++; // to simulate min-heap - used. If multiple task with same procTime, choose one with smallest idx
            if(not pq.empty()){
                auto [procTime , idx] = pq.top(); pq.pop();
                time -= procTime;
                ans.push_back(-idx);
            }else // no task available, smartly jump to next task
                time = tasks[i][0];
        }
        return ans;
    }
};


/*
Pretty interesting problem. Simulation problem with high constraint.
Have to keep track when CPU become idle.
Until then push tasks into priority queue sorted by processing time.
Binary search over tasks for CPU completion time?
Unnecessary.
*/