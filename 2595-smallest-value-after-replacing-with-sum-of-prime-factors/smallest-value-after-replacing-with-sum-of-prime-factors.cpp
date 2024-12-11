class Solution {
public:
    int smallestValue(int n , int sumOfPrimes = 0) {
        for(int divisor = 2 , m = n ; divisor <= n ; divisor++)
            for( ; m % divisor == 0 ; m /= divisor)
                sumOfPrimes += divisor;
        return sumOfPrimes == n ? n : smallestValue(sumOfPrimes);
    }
};

/*
Edge case : n = 4
*/