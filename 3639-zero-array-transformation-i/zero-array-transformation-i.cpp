class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size() , reduce = 0;
        vector <int> line(n + 1);
        for(auto &q : queries)
            line[q[0]] -= 1 , line[q[1] + 1] += 1;
        for(int i = 0 ; i < n ; i++){
            reduce += line[i];
            if((nums[i] + reduce) > 0)
                return false;
        }
        return true;
    }
};