class Solution {
public:
    int n , limit; 
    bool solve(int i , int target , vector <int> &sides , vector<int> &nums){
        if(i == n){
            for(int j = 0 ; j < 3 ; j++)
                if(sides[j] != sides[3])
                    return false;
            return true;
        } 
        bool ans = false;
        for(int j = 0 ; j < 4 ; j++){
            sides[j] += nums[i];
            if(sides[j] <= target)
                ans |= solve(i + 1 , target , sides , nums);
            sides[j] -= nums[i];
        }
        return ans;
    }
    bool makesquare(vector<int>& nums) {
        vector <int> sides = {0 , 0 , 0 , 0};
        sort(nums.rbegin() , nums.rend());
        n = nums.size() , limit = (1 << n) - 1;
        int sum = accumulate(nums.begin() , nums.end() , 0);
        return solve(0 , sum / 4 , sides , nums);
    }
};