class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans = 0;
        sort(pizzas.rbegin() , pizzas.rend());
        int n = pizzas.size() , total = n / 4 , odd = ceil(total / 2.0) , even = total - odd;
        int index = 0;
        for(int i = 0 ; i < odd ; i++)
            ans += pizzas[index++];
        index++;
        for(int i = 0 ; i < even ; i++ , index += 2)
            ans += pizzas[index];
        return ans;
    }
};