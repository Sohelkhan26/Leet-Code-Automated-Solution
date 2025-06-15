class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<vector<int>>& queries) {
        vector <ll> power(16 , 1);
        for(int i = 1 ; i < 16 ; i++) // power[i] = 4 ^ i
            power[i] = power[i - 1] * 4; // for faster O(1) lookup
        ll ans = 0;
        for(auto &q : queries){
            ll left = q[0] , right = q[1] , op = 0;
            for(int p = 1 ; p < 16 ; p++){ // p -> exponent
                ll L = max(left , power[p - 1]); // range of the query can be divided into many segments of power of 4
                ll R = min(right , power[p] - 1);
                if(R >= L) // if the power of 4 segment is inside the query
                    op += p * (R - L + 1);
            }
            ans += (op + 1) / 2; // can choose 2 number at once. 
        }
        return ans;
    }
};

/*
query given of length 1e5
each query has [l , r] , meaning the array contains numbers [l..r] so , array size could be very big 1e9
in one operation select two number and divide by 4
return sum of min op to turn each array to all 0
to process each query we can't just traverse through the array. we have to do it in <= O(100)
turn each element to 0 -> ceil(arr[i] / 4.0)
can we minimize op at all? they require what they require. no minimizing right?
4,4,16
select 4,4 -> 1 op
then 16 / 4 -> 4 op
compaired to select 4,16 -> 1
4,4 -> 1 = 2 operation
sorry my bad have to make 0, but that don't change the result. second case will have min op.
Above observation is wrong. query is on ranges. No duplicate and no minimizing the operation.
All numbers in the range:
[0..3] -> [4 ^ 0 .. 4 ^ 1 - 1] -> 1 op
[4..15] -> [4 ^ 1 .. 4 ^ 2 - 1] ->  2 op
[4 ^ n .. 4 ^ (n + 1) - 1] require (n + 1) operation. For some reason this don't work
Or , [4 ^ (n - 1) .. (4 ^ n) - 1] require n operaton
So we have to divide each query into some number of ranges.
*/