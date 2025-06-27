class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() , ans = 0 , maxOfLeft = INT_MIN;
        vector <int> suff(n);
        suff[n - 1] = arr.back();
        for(int i = n - 2 ; i >= 0 ; i--)
            suff[i] = min(suff[i + 1] , arr[i]);
        suff.push_back(INT_MAX);
        for(int i = 0 ; i < n ; i++){
            maxOfLeft = max(arr[i] , maxOfLeft);
            if(maxOfLeft <= suff[i + 1])
                ans++;
        }
        return ans;
    }
};