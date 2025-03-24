class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        int free = 0 , prevMeet = 1;
        sort(meet.begin() , meet.end());
        for(auto &m : meet){
            free += max(0 , m[0] - prevMeet);
            prevMeet = max(prevMeet , m[1] + 1);
            if(prevMeet > days)
                break;
        }
        return free + max(0 , days - prevMeet + 1);
    }
};