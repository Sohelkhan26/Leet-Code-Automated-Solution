class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0 , n = nums1.size() , K = k1 + k2 , total = 0 , t = 0;
        priority_queue <int> pq;
        for(int i = 0 ; i < n ; i++)
            pq.push(abs(nums1[i] - nums2[i])) , total += abs(nums1[i] - nums2[i]);
        if(K >= total)
            return 0;
        while(K > 0){
            t = pq.top(); pq.pop();
            long long reduce = pq.empty() ? K : max(K / n , 1ll);
            t -= reduce , K -= reduce;
            pq.push(t);
        }
        while(not pq.empty())
            ans += pow(pq.top() , 2) , pq.pop();
        return ans;
    }
};

/*
Main observation is combining the two array don't change the answer. 
Increasing one element in first array is same as decreasing same element in the second array.
As long as either k1 or k2 remains, change is possible.
But k1 , k2 <= 10^9 , so +1 , -1 -> TLE.
We have to reduce square of difference. We can just reduce the biggest difference as long as we have k1 or k2. Right? No, We can't overdo it. Two diff = 5 , 5 , K = 5, changing one element to 0 will yeild ans = 25 , but we try to evenly decrease the two diff, ans = 9 + 4 = 13
So, we have to make max difference same as next max difference or 1 less. 
*/