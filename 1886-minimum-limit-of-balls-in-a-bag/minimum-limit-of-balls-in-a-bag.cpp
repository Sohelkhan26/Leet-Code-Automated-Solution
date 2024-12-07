class Solution {
public:
    bool allowed(vector<int> &nums , int Max , int op){
        int currMax = -1;
        for(int i : nums){
            if(i < Max) // nums sorted in descending order
                break;
            currMax = max(currMax , i);
            while(currMax > Max){
                if(op <= 0)
                    return false;
                currMax = ceil(currMax / 2.0); // If no of balls is odd one extra ball is in one bag
                op--;
            }
            if(currMax > Max)
                return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int op) {
        int n = nums.size() , low = 1 , high = *max_element(nums.begin() , nums.end()), mid , ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            int neededOp = 0;
            for(int i : nums)
                neededOp += (i - 1) / mid;
            if(neededOp <= op){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};