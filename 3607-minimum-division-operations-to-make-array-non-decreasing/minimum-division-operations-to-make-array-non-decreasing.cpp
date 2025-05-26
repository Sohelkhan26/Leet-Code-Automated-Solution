
class Solution {
public:
    int minOperations(vector<int>& nums) {
        auto div = [&](int n){
            for(int i = 2 ; i < n ; i++)
                if(n % i == 0)
                    return i;
            return n;
        };
        int n = nums.size() , ans = 0;
        for(int i = n - 1 ; i > 0 ; i--){
            if(nums[i - 1] > nums[i])
                nums[i - 1] = div(nums[i - 1]) , ans++;
            if(nums[i] < nums[i - 1])
                return -1;
        }
        return ans;
    }
};

/*
If you do as the problem asks, it gets accepted. 
Proper divisor of a number 'n' is a divisor that is strictly less than n
But the logic is : dividing a number by it's proper divisor
results in prime number. Since it's a prime number atmost 1 operation
can be performed on a number. I still don't get the logic.
*/