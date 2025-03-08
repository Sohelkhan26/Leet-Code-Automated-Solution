class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        long long ans = 0;
        sort(pizzas.rbegin() , pizzas.rend());
        int n = pizzas.size() , total = n / 4 , odd = ceil(total / 2.0) , even = total - odd;
        int index = 0;
        for(int day = 0 ; day < total ; day++){
            if(day < odd)
                ans += pizzas[index++];
            else
                ans += pizzas[index + 1] , index += 2;
        }
        return ans;
    }
};

/*
Optimal pizza eating strategy:
Odd days: eat largest one and smallest three.
Even days: eat largest two and smallest two.
for odd days, take the largest pizzas.
for even days, take the second largest pizza.
Since n % 4 == 0 always. There will always be enough pizzas.
*/