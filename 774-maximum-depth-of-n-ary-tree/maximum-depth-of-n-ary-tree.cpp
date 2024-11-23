class Solution {
public:
    int maxDepth(Node* root) {
        int depth = 0;
        if(not root)
            return 0;
        for(Node* child : root -> children)
            depth = max(depth , maxDepth(child));
        return depth + 1;
    }
};