class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = left.empty() ? 0 : *max_element(left.begin() , left.end());
        for(int pos : right)
            ans = max(ans , n - pos);
        return ans;
    }
};