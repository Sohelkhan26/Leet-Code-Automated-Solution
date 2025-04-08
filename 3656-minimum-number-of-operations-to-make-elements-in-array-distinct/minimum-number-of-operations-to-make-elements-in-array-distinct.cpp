class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> freq;
        for(int i = n - 1 ; i >= 0 ; i--)
            if(freq[nums[i]]++ == 1)
                return ceil((i + 1) / 3.0);
        
        return 0;
    }
};