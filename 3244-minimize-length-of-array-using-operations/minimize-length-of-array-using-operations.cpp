class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        int mn = *min_element(nums.begin() , nums.end()) , cnt = 0;
        for(int &n : nums){
            cnt += (n == mn);
            if(n % mn != 0)
                return 1;
        }
        return (cnt + 1) / 2;
    }
};

/*
Ordering of pair don't matter, out of the two pair any can be nums[i].
Avoid choosing nums[i] == nums[j], cause it will result in rem = 0, which can't be removed.
Most important observation is, every bigger number can be elemenated by pairing it with a smaller number.
So, min element can eleminate every other element, other than itself. At the end It's count will remain, they can be paired themselves.
So, answer = (cnt + 1) / 2. (cnt pair of min-element product cnt / 2 0 , extra min-element remains if there is any).
All the min-element can be eliminated if, there is some number in the nums array not divisible by min-element.
How? Then we make that element nums[i], so the remainder will be pushed back, since nums[j] = min-element, remainder will be less than min-element. And with the help of that remainder, every min-element can be eliminated. If there is no such nums[j]/remainder, (cnt + 1) / 2 min-element will remain.
*/