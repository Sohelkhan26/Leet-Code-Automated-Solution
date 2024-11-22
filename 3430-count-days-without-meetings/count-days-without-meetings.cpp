class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        sort(meet.begin() , meet.end());
        int n = meet.size() , off = 0 , left = meet[0][0] , right = meet[0][1];
        for(int i = 1 ; i < n ; i++){
            if(right >= meet[i][0])
                right = max(right , meet[i][1]);
            else{
                off += (right - left + 1);
                left = meet[i][0] , right = meet[i][1];
            }
        }
        off += (right - left + 1);
        return days - off;
    }
};