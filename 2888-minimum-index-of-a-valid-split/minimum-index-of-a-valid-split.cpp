class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = nums[0] , freq = 0 , domCount = 0 , n = nums.size() , count = 0;
        for(int i : nums){
            if(i == dominant)
                count++;
            else count--;
            if(count == 0)
                dominant = i , count = 1;
        }
        for(int i : nums)
            if(i == dominant)
                domCount++;
        for(int i = 0 ; i < n ; i++){
            freq += nums[i] == dominant;
            if(freq * 2 > i + 1 and (domCount - freq) * 2 > n - i - 1)
                return i;
        }
        return -1;
    }
};