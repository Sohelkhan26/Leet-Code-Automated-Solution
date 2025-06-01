class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size() , count = 1;
        vector <int> occur(n + 1 , -1);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == x)
                occur[count++] = i;
        }
        vector <int> ans;
        for(int &q : queries)
            ans.push_back(q <= n ? occur[q] : -1);
        return ans;
    }
};