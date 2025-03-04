class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long , vector<long> , greater<long> > pq(nums.begin() , nums.end());
        int ans = 0;
        while(not pq.empty()){
            long a = pq.top(); pq.pop();
            if(a >= k)
                break;
            long b = pq.top(); pq.pop();
            pq.push(2 * min(a , b) + max(a , b));
            ans++;
        }
        return ans;
    }
};