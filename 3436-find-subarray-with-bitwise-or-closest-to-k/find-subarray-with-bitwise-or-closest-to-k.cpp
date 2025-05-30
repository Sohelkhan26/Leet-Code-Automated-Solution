class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        unordered_set <int> prev;
        int ans = INT_MAX;
        for(int &n : nums){
            unordered_set <int> curr = {n};
            for(const int &p : prev)
                curr.insert(p | n);
            for(const int &i : curr)
                ans = min(ans , abs(k - i));
            swap(prev , curr);
        }
        return ans;
    }
};