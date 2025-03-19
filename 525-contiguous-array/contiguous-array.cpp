class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map <int,int> earliest;
        earliest[0] = -1;
        int n = nums.size() , count = 0 , ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            count += (nums[i] == 0 ? -1 : 1);
            if(earliest.find(count) == earliest.end())
                earliest[count] = i;
            else ans = max(ans , i - earliest[count]);
        }      
        return ans;
    }
};