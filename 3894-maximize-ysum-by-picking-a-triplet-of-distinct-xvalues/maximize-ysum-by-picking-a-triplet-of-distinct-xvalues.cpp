class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map <int,int> best;
        for(int i = 0 ; i < x.size() ; i++)
            best[x[i]] = max(best[x[i]] , y[i]);
        if(best.size() < 3)
            return -1;
        int a = -1 , b = -1 , c = -1;
        for(auto &[key , val] : best){
            if(val > a){
                c = max(b , c);
                b = max(a , b);
                a = val;
            }else if(val > b){
                c = max(c , b);
                b = val;
            }else if(val > c)
                c = val;
        }
        return a + b + c;
    }
};