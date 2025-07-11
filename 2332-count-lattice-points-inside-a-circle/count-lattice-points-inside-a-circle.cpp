class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set <pair<int,int>> points;
        for(auto &c : circles){
            int r = c[2];
            for(int x = -r ; x <= r ; x++)
                for(int y = -r ; y <= r ; y++)
                    if(x * x + y * y <= r * r)
                        points.insert({c[0] + x , c[1] + y});
        }
        return points.size();
    }
};