class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size() , ans = 0 , curr = 0;
        for(int i : values){
            ans = max(ans , curr + i); // i acts as previous but we don't do nums[i] - i. (j - i) is accounted for by - 1 in the next line. Because we are only concerned with distance
            curr = max(curr , i) - 1; // - 1 to account for -j
        }
        return ans;
    }
};