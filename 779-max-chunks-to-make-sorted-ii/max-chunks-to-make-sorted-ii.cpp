class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size() , ans = 0;
        long long sum1 = 0 , sum2 = 0;
        vector <int> v = arr;
        sort(v.begin() , v.end());
        for(int i = 0 ; i < n ; i++){
            sum1 += arr[i];
            sum2 += v[i];
            if(sum1 == sum2)
                ans++;
        }
        return ans;
    }
};