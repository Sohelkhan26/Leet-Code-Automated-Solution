class Solution {
public:
    vector<int> tree;
    void update(int treeIdx, int low, int high, int i, int len) {
        if (low == high) {
            tree[treeIdx] = max(tree[treeIdx] , len); // store max-len of subseq ending at 'i' , i is not index but number
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * treeIdx + 1, low, mid, i, len);
        else
            update(2 * treeIdx + 2, mid + 1, high, i, len);
        tree[treeIdx] = max(tree[2 * treeIdx + 1], tree[2 * treeIdx + 2]);
    }
    int query(int i, int low, int high, int left, int right) {
        if (right < low || high < left)
            return 0;
        if (low >= left && high <= right) 
            return tree[i];
        int mid = low + (high - low) / 2;
        int l = query(2 * i + 1, low, mid, left, right);
        int r = query(2 * i + 2, mid + 1, high, left, right);
        return max(l, r);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = *max_element(nums.begin() , nums.end());
        tree.resize(4 * n);
        for(int &i : nums){
            int lower = i - k;
            int len = 1 + query(0 , 0 , n , lower , i - 1); // find max len in range [lower , i - 1]
            // add 1 to include current number in the subsequence.
            update(0 , 0 , n , i , len); // max-len-of-subsequence ending at 'i' updated as len
        }
        return tree[0]; // contains max-len of all the subsequence in range[num[0] , nums[nums.size() - 1]]
    }
};

/*
Subsequence filling all the constraint in the problem are referred to as good seq.
for every number length of sequence ending at a number is 1(the number itself).
And for every number 'n' previous number can be in the range[n - k , n - 1] We can take any number 
from this range as the previous number. 
To find out length of subsequence ending at 9 we have to find the max length of subsequence ending at [6 , 8] 
for k = 3. But if we try to do it iteratively we will get TLE.
But query of a max number in a range can be performed in logn time using segment tree.
But segment tree performs query in a range of indices. So, we modify the segment tree code.
nums[i] <= 10^5 so, we will treat nums[i] as index.
Every tree node will store max len of subsequence ending at a number(could be any number) in the range [low , high]
Rest of the segment tree code is same. Note: we will build segment tree as we go.
*/