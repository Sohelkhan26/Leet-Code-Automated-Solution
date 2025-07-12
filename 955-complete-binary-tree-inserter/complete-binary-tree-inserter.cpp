class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this -> root = root;
    }
    
    int insert(int val){
        queue <TreeNode*> q;
        q.push(root);
        TreeNode* node = new TreeNode(val);
        while(not q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr -> left)
                q.push(curr -> left);
            else{
                curr -> left = node;
                return curr -> val;
            }
            if(curr -> right)
                q.push(curr -> right);
            else{
                curr -> right = node;
                return curr -> val;
            }
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/*
Tree reorganize after each insertion? no
why get_root() if root don't change? no idea it returns same every time
*/