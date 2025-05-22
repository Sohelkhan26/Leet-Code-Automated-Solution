class Solution {
public:
    vector<int> closestDivisors(int num) {
        int diff = INT_MAX;
        vector <int> ans = {0 , 0};
        auto div = [&](int num){
            for(int i = 1 ; i <= sqrt(num) ; i++)
                if(num % i == 0){
                    if(abs(i - num / i) < diff)
                        ans = {i , num / i} , diff = abs(i - num / i);
                }
            return ans;
        };
        div(num + 1) , div(num + 2);
        return ans;
    }
};