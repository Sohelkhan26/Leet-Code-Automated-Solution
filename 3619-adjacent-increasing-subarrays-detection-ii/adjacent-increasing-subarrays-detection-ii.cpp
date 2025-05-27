class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0 , n = nums.size() , prevLong = 0 , currLong = 1;
        for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1])
                currLong++;
            else
                prevLong = currLong , currLong = 1;
            ans = max({ans , min(prevLong , currLong) , currLong / 2});
        }
        return ans;
    }
};

/*
First thought 2 adjacent strictly increasing subarray means 1 strictly increasing subarray.
Let's just call subarray abiding by all the constraint good subarray.
Almost correct. We can either pass 1 good subarray as 2 good adjacent subarray or
there is a breaking point in between like 1,2,3,2,4,5,6 -> second 2 is breaking point.
So, if there is a breaking point, the min of the two good subarray is answer. To keep track of 
previous good subarray before the breaking point , we store it in the prevLong variable and 
calculate answer on every index. Or if there is no breaking point we split the one good subarray
and pass it as 2.
*/