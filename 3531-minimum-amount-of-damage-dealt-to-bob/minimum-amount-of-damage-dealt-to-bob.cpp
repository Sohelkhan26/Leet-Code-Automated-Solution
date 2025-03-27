class Solution {
public:
    typedef pair<int,int> p;
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        long long ans = 0 , n = damage.size() , total = 0;
        priority_queue <vector<double>> pq;
        for(int i = 0 ; i < n ; i++){
            total += damage[i];
            double time = ceil(health[i] / (power * 1.0));
            double maxDamage = damage[i] / time * 1.0;
            pq.push({maxDamage , (double) damage[i] , time});
        }
        while(not pq.empty()){
            auto it = pq.top(); pq.pop();
            int d = it[1] , t = it[2];
            ans += (total * t);
            total -= d;
        }
        return ans;
    }
};