class Solution {
public:
    int smallestValue(int n) {
        int prevN = -1;
        while(prevN != n){
            prevN = n;
            int sumOfPrimes = 0;
            for(int divisor = 2 ; divisor < n ; divisor++)
                while(n % divisor == 0){
                    n /= divisor;
                    sumOfPrimes += divisor;
                }
            if(n != 1)
                sumOfPrimes += n;
            n = sumOfPrimes;
        }
        return n;
    }
};

/*
Just simulate the process. Replace n with it's prime factors. Do this until n remains same in the next iteration.
*/