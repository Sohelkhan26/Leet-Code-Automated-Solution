class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        sort(reward.begin() , reward.end());
        unordered_set <int> ans = {0};
        for(int &r : reward){
            unordered_set <int> extendAns;
            for(const int &prev : ans){
                if(r > prev)
                    extendAns.insert(r + prev);
            }
            ans.insert(extendAns.begin() , extendAns.end());
        }
        return *max_element(ans.begin() , ans.end());
    }
};