class CBTInserter {
public:
    vector<TreeNode*> tree;
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0 ; i < tree.size() ; i++){
            if(tree[i] -> left)
                tree.push_back(tree[i] -> left);
            if(tree[i] -> right)
                tree.push_back(tree[i] -> right);
        }
    }
    
    int insert(int val) {
        int n = tree.size();
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if(n % 2)
            tree[(n - 1) / 2] -> left = node;
        else 
            tree[(n - 1) / 2] -> right = node;
        return tree[(n - 1) / 2] -> val; // parent node
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};
