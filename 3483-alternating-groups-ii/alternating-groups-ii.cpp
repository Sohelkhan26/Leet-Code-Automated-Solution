class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size() , ans = 0 , cnt = 1;
        for(int i = 0 ; i < n + k - 2 ; i++)
        {
            cnt = colors[i % n] == colors[(i + 1) % n] ? 1 : cnt + 1;
            ans += cnt >= k;
        }
        return ans;
    }
};