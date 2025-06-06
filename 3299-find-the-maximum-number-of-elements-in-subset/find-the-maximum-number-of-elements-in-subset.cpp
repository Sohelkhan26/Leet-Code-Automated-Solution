class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map <int,int> freq;
        for(int &i : nums)
            freq[i]++;
        int ans = freq[1] - (freq[1] % 2 == 0);
        for(auto [n , cnt] : freq){
            int len = 0;
            long target = n;
            while(target <= 1e9 and freq.contains(target) and freq[target] >= 2 and target != 1)
                len += 2 , target *= target; // freq[peak] == 1
            len += (freq.contains(target) ? 1 : -1); // if freq[peak] == 2 , then we overcounted 2,2,4,4 , make 4 peak so, make freq[4] = 1
            ans = max(ans , len);
        }
        return ans;
    }
};

/*
Subset follows a mountain sequence. And next number is square of previous number. nums[i] <= 10 ** 9. We easily fix a starting number x and find out the subset length. Sequence length will be small until it overflows.
Binary search over answer space ? 
Since nums[i] <= 1e9 , we can easily brute force until nums[i] gets out of bounds. Use map and brute force for next element.
Some edge case: If all subset element is 1 , then ans = count(1) what about 1,1,1,1 , then 1,1,1
freq[peak] should be 1. All other element 'x' freq[x] >= 2 (at least 2)
If there is no peak with freq[peak] = 1, then make one.
2,4,4,2 , then sacrifice one 4 and 2,4,2
*/