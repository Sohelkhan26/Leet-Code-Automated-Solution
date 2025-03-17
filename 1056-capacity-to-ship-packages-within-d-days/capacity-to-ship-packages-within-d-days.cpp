class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end()), high = 500 * 5 * 1e4 , capacity , ans;
        while(low <= high){
            capacity = low + (high - low) / 2;
            int load = 0 , day = 1;
            for(int i : weights){
                if(load + i > capacity){
                    day++;
                    load = i;
                }else load += i;
            }
            if(day <= days){
                ans = capacity;
                high = capacity - 1;
            }else low = capacity + 1;
        }
        return ans;
    }
};