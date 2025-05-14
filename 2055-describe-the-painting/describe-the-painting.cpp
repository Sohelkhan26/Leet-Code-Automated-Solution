class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map <int,long long> line;
        unordered_map <int,bool> ends;
        vector<vector<long long>> ans;
        for(auto it : segments){
            line[it[0]] += it[2];
            line[it[1]] -= it[2];
            ends[it[0]] = true;
            ends[it[1]] = true;
        }
        long long sum = 0 , prev = -1;
        for(auto &[start , color] : line){
            if(ends[start] and sum)
                ans.push_back({prev , start , sum});
            if(ends[start])
                prev = start;
            sum += color;
        }
        return ans;
    }
};