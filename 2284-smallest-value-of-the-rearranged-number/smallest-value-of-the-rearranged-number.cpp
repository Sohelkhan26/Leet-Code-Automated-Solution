class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0)
            return 0;
        auto solve = [&](long long n){
            long long ans = 0;
            bool neg = (n < 0); n = abs(n);
            vector <int> v;
            while(n > 0)
                v.push_back(n % 10) , n /= 10;
            if(neg)
                sort(v.rbegin() , v.rend());
            else{
                sort(v.begin() , v.end());
                int i = 0;
                while(v[i] == 0)
                    i++;
                swap(v[i] , v[0]);
            }
            for(int &i : v)
                ans = (ans * 10 + i) , cout << i << ' ';
            return neg ? ans * -1 : ans;
        };
        return solve(num);
    }
};