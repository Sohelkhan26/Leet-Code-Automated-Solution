class Solution {
public:
    typedef pair<int,int> p;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size() , i = 0 , ans = 0;
        priority_queue < p , vector<p> , greater<> > pq;
        while(not pq.empty() or i < n){
            if(i < n)
                pq.push({i + days[i] , apples[i]});
            while(not pq.empty() and (pq.top().first <= i or pq.top().second == 0))
                pq.pop();
            if(not pq.empty()){
                auto curr = pq.top(); pq.pop();
                if(curr.second)
                    ans++ , curr.second--;
                if(curr.second)
                    pq.push(curr);
            }
            i++;
        }
        return ans;
    }
};