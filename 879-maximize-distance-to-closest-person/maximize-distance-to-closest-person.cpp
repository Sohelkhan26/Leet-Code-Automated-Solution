class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = -1 , prev = 0 , n = seats.size();
        for(int i = 0 ; i < n ; i++){
            if(seats[i]){
                if(ans == -1)
                    ans = i;
                else ans = max(ans , (i - prev) / 2);
                prev = i;
            }
        }
        return max(ans , n - 1 - prev);
    }
};