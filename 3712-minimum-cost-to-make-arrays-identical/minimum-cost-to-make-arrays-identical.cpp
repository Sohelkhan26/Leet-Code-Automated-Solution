class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0;
        auto calc = [&]() -> long long{
            long long sum = 0;
            for(int i = 0 ; i < arr.size() ; i++)
                sum += abs(arr[i] - brr[i]);
            return sum;
        };
        ans = calc();
        sort(arr.begin() , arr.end());
        sort(brr.begin() , brr.end());
        return min(ans , calc() + k);
    }
};
/*
First opertion lets us rerrange in any order. So, basically sort.
Case 1: arr , brr permutation of each other, don't need first operation.
Difference = 0 , ans = k
Case 2 : arr != brr even after sorting (not permutation of each other) , we need to do operation 1 as well as 2. ans = diff(arr[i] - brr[i]) + k
*/