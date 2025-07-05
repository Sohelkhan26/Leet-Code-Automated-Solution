class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size(), mod = 1e9 + 7;
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + nums[i];

        long long ans = 0;
        vector<pair<int, int>> st; // pair: <index, start of range>

        for (int i = 0; i < n; ++i) {
            int newStart = i;
            while (!st.empty() && nums[st.back().first] > nums[i]) {
                auto [idx, start] = st.back(); st.pop_back();
                long long total = pref[i] - pref[start];
                ans = max(ans, total * nums[idx]);
                newStart = start; // extend to the left
            }
            st.emplace_back(i, newStart);
        }

        // Remaining elements in stack
        for (auto [idx, start] : st) {
            long long total = pref[n] - pref[start];
            ans = max(ans, total * nums[idx]);
        }

        return ans % mod;
    }
};
