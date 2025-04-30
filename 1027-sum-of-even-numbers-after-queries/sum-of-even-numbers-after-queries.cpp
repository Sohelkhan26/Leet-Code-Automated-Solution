class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = accumulate(nums.begin() , nums.end() , 0 , [&](int sum , int i){
            return sum + (i % 2 == 0 ? i : 0);
        });
        vector <int> ans;
        for(auto &q : queries){
            int val = q[0] , i = q[1];
            if(nums[i] % 2 == 0)
                sum -= nums[i];
            nums[i] += val;
            if(nums[i] % 2 == 0)
                sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};

/*
This was so easy, yet I spent more time than ever. Thinking of four cases if the old was odd and newVal was even etc.
Sometimes even the basics of problem seems pretty hard to me.
All This problem asks is to do as it says. Nothing more nothing less.
Take all even values. They will definitely contribute to sum. For each query if the value at effected index was previously even we remove from sum. For the new value Do the same. 
*/