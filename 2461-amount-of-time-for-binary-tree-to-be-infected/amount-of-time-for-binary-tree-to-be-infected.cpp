class Solution {
public:
    int ans = 0;
    int solve(TreeNode* root , int start){
        int depth = 0;
        if(not root)
            return depth;
        int leftDepth = solve(root -> left , start);
        int rightDepth = solve(root -> right , start);
        if(root -> val == start){
            ans = max(leftDepth , rightDepth); // এই node যদি root node হয় তাহলে এটাই এনসার। পরে এটা আর আপডেট হবে না। তা না হলে start node tree এর মাঝের কোন একটা নোড। রুট নোড থেকে start নোড এর distance জানতে হবে। -ve value return করে মানে এই পাশে start node আছে। এবং এই নেগেটিভে ভ্যালুর absolute value নির্দেশ করে কয় লেভেল পরে আছে। 
            depth = -1;
        }else if(min(leftDepth , rightDepth) >= 0)
            depth = max(leftDepth , rightDepth) + 1; // মানে এই সাবট্রিতে start node নেই। 
        else {
            ans = max(ans , abs(leftDepth) + abs(rightDepth));
            depth = min(leftDepth , rightDepth) - 1; // subtract one to account for each level
        }
        return depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root , start);
        return ans;
    }
};
/*
start node যদি root node হয় তাহলে ট্রির হাইট ই এনসার। তা না হয়ে যদি মাঝখানের কোন node start হয় তাহলে এনসার হবে distance(root -> furthest leaf) + distance(root -> start) উল্লেখ্য যে, furthest leaf মানে, যে subtree তে start নেই সেই subtree এর furthest leaf.
                            10
                         /      \
                        1        2
                       /  \     /  \
                      3    4   5    6
                    /   \          /  \
                   7     8        24   32
6 যদি start node হয় তাহলে ১০ -> ৬ এর দূরত্ব + ১০ -> ৭ বা ১০ -> ৮ এর দূরত্ব এর যোগফল রিটার্ন করতে হবে। ১০ -> ৬ এর দূরত্ব কিভাবে বের হবে? ৬, ২ কে -১ রিটার্ন করবে। ২ আবার ১০ কে -১ -১ = -২ রিটার্ন করবে। abs(-2) = 2 মানে দুই লেভেল পরে start নোড আছে। -ve indicates start node
ট্রি যদিঃ 2
        \
          6
            \
              32
                 \
                  100
                     \
                      10 
এরকম  হতো তাহলে ans = max(leftDepth , rightDepth); এই লাইনের মাধ্যমে এনসার বের হয়ে যেতো। 
                
*/