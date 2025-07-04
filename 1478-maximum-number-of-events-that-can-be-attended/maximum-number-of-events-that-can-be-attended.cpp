class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue <int> pq;
        sort(events.begin() , events.end());
        int i = 0 , n = events.size() , ans = 0;
        for(int day = 1 ; day <= 1e5 ; day++){
            while(not pq.empty() and -pq.top() < day)
                pq.pop();
            while(i < n and events[i][0] == day)
                pq.push(-events[i++][1]);
            if(not pq.empty())
                ans++ , pq.pop();
        }
        return ans;
    }
};

/*
Greedy will work. try to attend event as soon as possible. keep track of last attendence day.
*/