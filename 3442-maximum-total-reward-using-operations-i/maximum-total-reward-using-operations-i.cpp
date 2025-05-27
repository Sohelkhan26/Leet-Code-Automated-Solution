class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        sort(reward.begin() , reward.end());
        set <int> ans = {0};
        for(int &r : reward){
            set <int> extendAns;
            for(const int &prev : ans){
                if(r > prev)
                    extendAns.insert(r + prev);
            }
            ans.insert(extendAns.begin() , extendAns.end());
        }
        return *prev(ans.end());
    }
};

/*
Really cool solution. First thought of greedy. Gradually pick smaller.
That doesn't gaurantee maximum answer. To get the optimal answer, we need to use DP , pick or not pick type. But the total-reward is gonna pose a problem.
What could be the max-total-reward? Probably some type of complext math is involved. Instead we go with this approach, Some other problem was solved by this method before. 
First set contains all possible sum of subsequence of rewards[i]. Now for each new reward we try to extend our answer by including it if reward[i] is greater than our current answer. It's same as DP but instead of keeping track of index and current score/answer, we keep only answer.
unordered_set used for better efficiency.
*/