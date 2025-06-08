class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long total = 0;
        priority_queue <pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(int i = 0 ; i < n ; i++)
            pq.push({nums[i], i}) , total += nums[i];
        vector <long long> ans;
        for(auto &q : queries){
            int i = q[0] , k = q[1];
            total -= nums[i] , nums[i] = 0;
            while(not pq.empty() and k){
                if(nums[pq.top().second]){
                    total -= nums[pq.top().second];
                    nums[pq.top().second] = 0;
                    k--;
                }
                pq.pop();
            }
            ans.push_back(total);
        }
        return ans;
    }
};