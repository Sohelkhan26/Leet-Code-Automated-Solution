class NumArray {
public:
    int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        function<void(int,int,int)> build = [&](int treeIdx , int low , int high){ // place sum of range nums[low , high] at tree[treeIdx]
            if(low == high){ // sum of range [0..0] is nums[0]
                tree[treeIdx] = nums[low];
                return;
            }
            int mid = low + (high - low) / 2; // we don't want to do stranious work, so divide them among my 2 children
            build(2 * treeIdx + 1 , low , mid); // left child will calculate sum in range[low , mid]. I ordered him to place the sum at 2 * treeIdx + 1
            build(2 * treeIdx + 2 , mid + 1 , high); // right child calculate sum in range[mid + 1 , high], place sum at 2 * treeIdx + 2
            tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
        };
        build(0 , 0 , n - 1);
    }
    
    void update(int i, int val) {
        function<void(int,int,int)> change = [&](int treeIdx , int low , int high){
            // treeIdx contains sum of range[low , high] and index that should be updated also lie in this range. So value at this index should be updated.
            // so this function was called. high , low is only for checking if the index lies in the range or not
            if(low == high){ // this
                tree[treeIdx] = val;
                return;
            }
            int mid = low + (high - low) / 2;
            if(i <= mid)
                change(2 * treeIdx + 1 , low , mid);
            else change(2 * treeIdx + 2 , mid + 1 , high);
            tree[treeIdx] = tree[2 * treeIdx + 1] + tree[2 * treeIdx + 2];
        };  
        change(0 , 0 , n - 1);
    }
    
    int sumRange(int left, int right) {
        function<int(int,int,int)> sum = [&](int low , int high , int treeIdx){
            // find sum of range [left , right] , but tree[treeIdx] contains sum of [low , high]
            if(left > high or right < low) // nothing common in the target and have ranges.
                return 0;
            if(left <= low and high <= right) // target range [left , right] completely lies within [low , high]
                return tree[treeIdx];
            int mid = low + (high - low) / 2;
            return sum(low , mid , 2 * treeIdx + 1) + sum(mid + 1 , high , 2 * treeIdx + 2);
        };
        return sum(0 , n - 1 , 0);
    }
};