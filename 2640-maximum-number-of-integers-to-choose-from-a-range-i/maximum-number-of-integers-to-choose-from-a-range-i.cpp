class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin() , banned.end());
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            if(binary_search(banned.begin() , banned.end() , i))
                continue;
            if((maxSum = maxSum - i) < 0)
                break;
            ans++;
        }
        return ans;
    }
};