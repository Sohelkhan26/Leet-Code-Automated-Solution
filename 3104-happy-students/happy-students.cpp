class Solution {
public:
    int countWays(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for (int num : nums) 
            freq[num]++;

        int less = 0, ans = 0;
        for (int group = 0; group <= n; group++) {
            less += freq[group];
            if (freq[group] == 0 && less == group) {
                ans++;
            }
        }
        return ans;
    }
};

/*
Interesting problem.
total number of selected students is group size.
group size can be [0..n] group size can't be greater than number of students.
so, possible group size is the number of ways to select a group.
if we sort nums, nums[0] <= nums[1] <= nums[2]...
if we select i'th student, all nums[j] (j <= i) need to be less than (<) group size.
so, if we select i'th student, all previous students must be also be selected.
so , group size is (i + 1), and no student with nums[k] >= nums[i] can be selected.
if this is satisfied, this group size is valid and we found a new way.
one edge case: group size can be 0 which is not covered in the loop.
If nums[0] is not 0, we can make a group with no student.
0'th student is not chosen, so group size < nums[0]
*/