class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        while(arr.size() > 1){
            auto mn = min_element(arr.begin() , arr.end());
            int i = mn - arr.begin();
            int left = i - 1 >= 0 ? arr[i - 1] : INT_MAX;
            int right = i + 1 < arr.size() ? arr[i + 1] : INT_MAX;
            ans += (*mn) * min(left , right);
            arr.erase(arr.begin() + i);
        }
        return ans;
    }
};

/*
Certain  crucial observations:
arr is the in-order traversal of the binary tree. In other words, order of arr can't be changed.
Value of non-leaf node = max(left , right). Only leaf node is considered. Even if other non-leaf node's value is max we can't allow it to build other leaf node. If it was allowed, then the answer would be the product of arr.
So, non-leaf node only contribute to the answer. They don't contribute to build other non-leaf nodes.
Now this problem can be phrased like this: given a array, 
you can perform this operation until only one element remains:
take one element and either pair it with either of it's adjacent elements and add their product to answer. 
Do these operation to minimize answer.
So, we have to minimize the product as much as we can.
Be greedy: Take the smallest element and pair it with smallest adjacent element. (adjacent element only because Binary tree).
Since, other leaf nodes are concerned with maximum element of it's left and right subtree, the smallest element may as well as go to hell.(remove from arr)
*/