class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size() , m = mat[0].size();
        vector<vector<int>> pref(n + 1 , vector<int> (m + 1 , 0));
        for(int i = 1 ; i <= n ; i++) // standard code for calculating 2D prefix sum
            for(int j = 1 ; j <= m ; j++) // to account for offset by one , use mat[i-1][j-1] instead of mat[i][j]
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];

        int low = 0 , high = min(n , m) , mid , ans;
        auto compare = [&](int len){
            for(int i = len ; i <= n ; i++)for(int j = len ; j <= m ; j++) // pref[i][j] contains 2D sum up until this co-ordinate. Can be related with the previous formula. we want sum of the square.
                if(pref[i][j] - pref[i - len][j] - pref[i][j - len] + pref[i - len][j - len] <= threshold)
                    return true; // pref[i - len][j - len] was subtracted twice so adding once.
            return false;
        };
        while(low <= high){ // standard BS
            mid = low + (high - low) / 2;
            if(compare(mid)) // Have to find highest square side
                ans = mid , low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
// To know more about 2D prefix sum , refer to this article: https://usaco.guide/silver/more-prefix-sums?lang=cpp