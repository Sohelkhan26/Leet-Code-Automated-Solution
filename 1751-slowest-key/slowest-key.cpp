class Solution {
public:
    char slowestKey(vector<int>& time , string key) {
        pair <int,char> mx = {time[0] , key[0]};
        for(int i = 1 ; i < time.size() ; i++){
            mx = max(mx , {time[i] - time[i - 1] , key[i]});
        }
        return mx.second;
    }
};