class Solution {
public:
    long long maximumPoints(vector<int>& e, int energy) {
        long long ans = 0 , n = e.size();
        sort(e.begin() , e.end());
        if(energy < e[0])
            return 0;
        for(int right = n - 1 ; right >= 0 ; ){
            if(e[0] <= energy){
                int d = energy / e[0];
                ans += d;
                energy -= (d * e[0]);
            }else{
                energy += e[right--];
            }
        }
        return ans;
    }
};