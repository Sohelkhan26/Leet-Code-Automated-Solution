class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        map <int,long long> line;
        for(auto it : seg){
            line[it[0]] += it[2];
            line[it[1]] -= it[2];
        }
        int prev = -1;
        vector<vector<long long>> ans;
        long long sum = 0;
        for(auto &[curr , color] : line){
            if(sum != 0 and prev != -1)
                ans.push_back({prev , curr , sum});
            sum += color;
            prev = curr;
        }
        return ans;
    }
};