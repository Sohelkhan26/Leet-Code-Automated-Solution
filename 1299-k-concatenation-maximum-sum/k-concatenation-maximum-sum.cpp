class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size() , mod = 1e9 + 7;
        long long total = accumulate(arr.begin() , arr.end() , 0ll) , sum = 0 , maxSum = 0;
        for(int i = 0 ; i < n * min(k , 2) ; i++){
            sum += arr[i % n];
            maxSum = max(maxSum , sum);
            if(sum < 0)
                sum = 0;
        }
        return max({0ll , maxSum , maxSum + total * max(0 , k - 2)}) % mod;
    }
};

/*
Cases:
1. ans = 0
2. ans = sum(arr) * k
3. ans = suffix + sum(arr * (k - 2)) + prefix (k >= 2)
*/