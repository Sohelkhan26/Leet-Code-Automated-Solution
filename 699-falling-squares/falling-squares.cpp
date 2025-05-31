/*Modified height should be updated over a range. So we gonna need rangeUpdate instead of point update in other words lazy propagation.*/
class Solution {
public:
    vector<int> tree, lazy;
    void push(int i, int low, int high) {
        if (lazy[i]) {
            tree[i] = max(tree[i], lazy[i]);
            if (low != high) { // if it's not a leaf node , update lazy nodes of child
                lazy[2 * i + 1] = max(lazy[2 * i + 1], lazy[i]);
                lazy[2 * i + 2] = max(lazy[2 * i + 2], lazy[i]);
            }
            lazy[i] = 0;
        }
    }
    void rangeUpdate(int root , int low , int high , int qL , int qR , int val){
// update heights in range [qL , qR] to new height
        push(root , low , high); 
        if(qR < low or qL > high)
            return;
        if(qL <= low and high <= qR){
            lazy[root] = val;
            push(root , low , high);
            return;
        }
        int mid = low + (high - low) / 2;
        rangeUpdate(2 * root + 1 , low , mid , qL , qR , val);
        rangeUpdate(2 * root + 2 , mid + 1 , high , qL , qR , val);
        tree[root] = max(tree[2 * root + 1] , tree[2 * root + 2]);
    }
    int query(int root , int low , int high , int qL , int qR){ // find max stack height in the range [qL , qH]
        push(root , low , high);
        if(qR < low or qL > high)
            return 0;
        if(qL <= low and high <= qR)
            return tree[root];
        int mid = low + (high - low) / 2;
        int l = query(2 * root + 1 , low , mid , qL , qR);
        int r = query(2 * root + 2 , mid + 1 , high , qL , qR);
        return max(l , r);
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> compress;
        for (auto& pos : positions)
            compress.insert({pos[0], pos[0] + pos[1] - 1});
        int t = 0, maxH = 0;
        unordered_map<int, int> idx;
        for (const int& x : compress)
            idx[x] = t++;
        tree.resize(4 * t) , lazy.resize(4 * t); // all the position ended at t - 1
        vector<int> heights(t), ans;
        for (auto& p : positions) {
            int left = idx[p[0]], right = idx[p[0] + p[1] - 1], height = 0;
            height = query(0, 0, t - 1 , left, right) + p[1]; 
            rangeUpdate(0 , 0 , t - 1 , left , right , height); // updates stack heights in this range as the new height.
            maxH = max(maxH, height);
            ans.push_back(maxH);
        }
        return ans;
    }
};
