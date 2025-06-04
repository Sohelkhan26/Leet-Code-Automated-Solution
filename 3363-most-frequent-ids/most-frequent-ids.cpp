class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map <int,long long> mp;
        vector <long long> ans;
        priority_queue <pair<long long,int>> pq; // {freq , id}
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]] += freq[i];
            pq.push({mp[nums[i]] , nums[i]});
            while(not pq.empty() and mp[pq.top().second] != pq.top().first)
                pq.pop();           // actual freq             freq in pq
            ans.push_back(pq.empty() ? 0 : pq.top().first);
        }
        return ans;
    }
};

/*
Update frequency of each number in map and priority_queue.
But pq will have highest frequency number at top, so updating frequency in pq is inefficient. So, we just push new frequency as we go.
So, this can result in incorrect frequency at the top. {id [2,2,5] , freq [3,-3,5]} So, pop top elements if their frequency aren't equal to actual fruquency stored in the map.
*/