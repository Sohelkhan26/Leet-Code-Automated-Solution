class Solution {
public:
    vector<int> tree;
    void update(int treeIdx, int low, int high, int i) {
        if (low == high) {
            tree[treeIdx] = 1;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * treeIdx + 1, low, mid , i);
        else
            update(2 * treeIdx + 2, mid + 1, high , i);
        tree[treeIdx] = (tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2]);
    }
    int findMax(int i, int low, int high, int left, int right) {
        if (right < low || high < left)
            return 0;
        if (low >= left && high <= right) 
            return tree[i];
        int mid = low + (high - low) / 2;
        int l = findMax(2 * i + 1, low, mid, left, right);
        int r = findMax(2 * i + 2, mid + 1, high, left, right);
        return l + r;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> idx;
        int n = nums1.size();
        for(int i = 0 ; i < n ; i++)
            idx[nums2[i]] = i;
        tree.resize(4 * n);
        long long ans = 0;
        // update(0 , 0 , n - 1 , idx[nums1[0]]);
        for(int i = 0 ; i < n ; i++){
            int j = idx[nums1[i]];
            int leftCommon = findMax(0 , 0 , n - 1 , 0 , j);
            int leftNotCommon = i - leftCommon; // all previous values are marked. If they are not on left side, they must be on right side.
            int rightElementInNums2 = n - 1 - j; // count of elements on the right side of nums2.
            int rightCommon = rightElementInNums2 - leftNotCommon; 
            ans += (1ll * leftCommon * rightCommon);
            update(0 , 0 , n - 1 , j); // mark previous values as visited.
        }
        return ans;
    }
};

/*
Segment tree is used for nums2.
Traverse nums1 and mark previous elements as visited(1).
For current number in nums1, find it's index in nums2. 
Find number of visited index to it's left. Count number of visited indices, it means it was previously encountered in nums1, that's why it is marked visited. So, they are left common part for both array. Can't describe properly. Dry run.
*/