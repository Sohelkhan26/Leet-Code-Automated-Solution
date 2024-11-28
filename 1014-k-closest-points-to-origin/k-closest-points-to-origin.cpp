class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <vector<int>> pq;
        for(auto it : points){
            int x = it[0] , y = it[1];
            pq.push({x * x + y * y , x , y});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            ans.push_back({it[1] , it[2]});
        }
        return ans;
    }
};