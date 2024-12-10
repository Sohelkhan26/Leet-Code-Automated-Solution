class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1 , high = *max_element(candies.begin() , candies.end()) , mid , ans = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            long long children = 0;
            for(int i : candies)
                children += (int)(i / mid);
            if(children >= k){
                ans = mid;
                low = mid + 1;
            }else high = mid - 1;
        }
        return ans;
    }
};
/*
Binary search over the maximum number of candies. So mid is the possible answer. If a pile has more than mid candies, we have to split it in such a way so that we can assign same number of candies to as many children possible. If a pile has 12 candies we want to split it as 5 , 5 so that we can give it to 2 children rather than 1 chilren. So 12 -> 5 , 7 . 7 -> 5 , 2
*/