class Solution {
public: 
    bool canCut(vector<pair<int,int>>& line){
        int prev = line[0].second , n = line.size() , cut = 1;
        for(int i = 1 ; i < n ; i++){
            if(prev > line[i].first)
                prev = max(prev , line[i].second);
            else
                cut++ , prev = line[i].second;
        }
        cout << cut << endl;
        return cut >= 3;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector <pair<int,int>> hor , ver;
        for(auto rect : rectangles){
            int x1 = rect[0] , y1 = rect[1] , x2 = rect[2] , y2= rect[3];
            hor.push_back({x1 , x2});
            ver.push_back({y1 , y2});
        }
        sort(hor.begin() , hor.end());
        sort(ver.begin() , ver.end());
        return canCut(hor) or canCut(ver);
    }
};