/**
Tree এর height বের করার জন্য কিন্তু লেফট বা রাইট সাবট্রি যেটার height বেশী সেটা নিতে হয়। এটা মাথায় রাখতে হবে। যেকোন সাবট্রি height-balanced না হলে কিন্তু পুরো Tree ই height-imbalanced হয়। 
*/
class Solution {
public:
    int solve(TreeNode* root){
        if(not root)
            return 0;
        int leftLen = solve(root -> left) , rightLen = solve(root -> right);
        if(leftLen == -1 or rightLen == -1 or abs(rightLen - leftLen) > 1)
            return -1;
        return max(leftLen , rightLen) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return solve(root) != -1;
    }
};