class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue <TreeNode*> q;
        q.push(root);
        while(not q.empty()){
            int n = q.size();
            vector<int> raw , sorted;
            while(n--){
                TreeNode* root = q.front();
                q.pop();
                raw.push_back(root -> val);
                sorted.push_back(root -> val);
                if(root -> left)
                    q.push(root -> left);
                if(root -> right)
                    q.push(root -> right);
            }
            unordered_map <int,int> index;
            for(int i = 0 ; i < raw.size() ; i++)
                index[raw[i]] = i; 
            sort(sorted.begin() , sorted.end());
            for(int i = 0 ; i < raw.size() ; i++){
                if(raw[i] != sorted[i]){ 
                    ans++;
                    int j = index[sorted[i]];
                    index[raw[i]] = j;
                    swap(raw[i] , raw[j]);
                }
            }
        }
        return ans;
    }
};

/*
sorted array এর সাথে কোন ভ্যালু না মিললেই swap করতে হবে। swap করলে হয় একটা ভ্যলু কারেক্ট পজিশনে যাবে, বা দুইটাও যাইতে পারে। তাই এত হাবিজাবি করতে হইছে। 
*/