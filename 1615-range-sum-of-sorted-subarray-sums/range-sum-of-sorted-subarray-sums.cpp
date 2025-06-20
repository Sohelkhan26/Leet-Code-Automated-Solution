class Solution {
public:
    typedef pair<int,int> P;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue <P , vector <P> , greater<P>> pq;
        int ans = 0 , mod = 1e9 + 7;
        for(int i = 0 ; i < n ; i++)
            pq.push({nums[i] , i}); // subarray starting at each index
        for(int remove = 0 ; remove < right ; remove++){ // go until (right - 1) cause 1 indexed
            auto [sum , i] = pq.top(); pq.pop();
            if(remove >= left - 1) // only take if we removed first (left - 1) smallest subarray sums
                ans = (ans + sum) % mod;
            if(i + 1 < n)
                pq.push({sum + nums[i + 1] , i + 1}); // expand subarray
        }
        return ans;
    }
};

/*
Suppose we have all subarray sums in sorted order.
Skip first left - 1 (cause 1 indexed) and take until right - 1
That's what is being done. 
How are subarray sums computed? start at index i, expand until n - 1.
calculate their sum and store in pq to skip to smallest (left - 1) subarray sums.
*/