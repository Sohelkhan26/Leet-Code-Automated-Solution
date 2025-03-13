class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0 , n = queries.size() , high = n , mid , ans = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            bool ok = true;
            vector <int> line(100001);
            for(int i = 0 ; i < mid ; i++){
                int l = queries[i][0] , r = queries[i][1] , val = queries[i][2];
                line[l] += val;
                line[r + 1] -= val;
            }
            int total = 0;
            for(int i = 0 ; i < nums.size() ; i++){
                total += line[i];
                if(total < nums[i]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};

/*
The problem requires binary search. If k queries are enough to make nums a zero array, then k + 1 will also suffice. As we are required to find the minimum, we should check for k - 1 and so on.
If we check for modifying the nums array directly everytime we will certainly get TLE.
So, used a line sweep to avoid repetetive interval queries.
As values between the intervals are 0, it doesn't affect the "total" value.
*/
