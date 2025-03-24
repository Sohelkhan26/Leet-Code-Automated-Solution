class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        int n = meet.size() , busy = 0;
        sort(meet.begin() , meet.end());
        vector <int> prev = meet[0];
        for(int i = 1 ; i < n ; i++){
            if(prev[1] >= meet[i][0]) // overlap of schedules
                prev[1] = max(meet[i][1] , prev[1]); // Think of how sorting works, value at index 0 is increasing for sure, but not at index 1
            else{
                busy += (prev[1] - prev[0] + 1);
                prev = meet[i];
            }
        }
        busy += (prev[1] - prev[0] + 1);
        return days - busy;
    }
};
/*
Count the number of days there is a meeting, return days - count.
There could be overlapping meeting schedule. Take care of that.
*/