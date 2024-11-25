/*
For each node If it has same number of nodes in the left and right subtree then it's a perfect binary tree. If it is we save it's size in a priority queue. 
If it's not a binary tree we return -1 and don't push it into the priority queue.
*/
class Solution {
public:
    priority_queue<int> pq;
    int solve(TreeNode* root){
        if(not root)
            return 0;
        int leftLen = solve(root -> left);
        int rightLen = solve(root -> right);
        if(leftLen == rightLen and leftLen >= 0){
            pq.push(leftLen + rightLen + 1);
            return leftLen + rightLen + 1;
        }
        return -1;
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        solve(root);
        k--;
        while(k-- and not pq.empty())
            pq.pop();
        return pq.empty() ? -1 : pq.top();
    }
};