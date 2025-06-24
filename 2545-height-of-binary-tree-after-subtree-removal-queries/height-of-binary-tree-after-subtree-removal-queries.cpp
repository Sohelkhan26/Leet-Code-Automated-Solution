class Solution {
public:
    unordered_map<int, int> depth, height;
    unordered_map<int, vector<pair<int, int>>> cousins;

    int dfs(TreeNode* node, int d) {
        if (!node) return -1;

        int leftHeight = dfs(node->left, d + 1);
        int rightHeight = dfs(node->right, d + 1);

        int h = max(leftHeight, rightHeight) + 1;
        depth[node->val] = d;
        height[node->val] = h;

        // Store top 2 heights for each depth level (negative for max-heap behavior)
        auto& v = cousins[d];
        v.push_back({h, node->val});
        sort(v.rbegin(), v.rend());
        if (v.size() > 2) v.pop_back();

        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root, 0);

        vector<int> res;
        for (int q : queries) {
            int d = depth[q];
            const auto& v = cousins[d];

            if (v.size() == 1) {
                res.push_back(d - 1); // No cousin at that depth
            } else if (v[0].second == q) {
                res.push_back(v[1].first + d); // Skip the removed node, take 2nd best
            } else {
                res.push_back(v[0].first + d); // Top height remains
            }
        }
        return res;
    }
};
