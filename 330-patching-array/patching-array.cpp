class Solution {
public:
    int minPatches(vector<int>& nums, int target) {
        long canMake = 0 , patch = 0;
        for(int i = 0 ; i < nums.size() and nums[i] <= target ; i++){
            int n = nums[i];
            while(n > canMake + 1)
                canMake += (canMake + 1) , patch++;
            canMake += n;
        }
        while(canMake < target)
            canMake += (canMake + 1) , patch++;
        return patch;
    }
};