class Solution {
public:
    bool solve(int n , int power){
        if(n == 0)
            return true;
        // if(n % 3 != 0)
        //     return false;
        bool ans = false;
        while(power != 16)
            ans |= solve(n - pow(3 , power) , power + 1) , power++;
        return ans;
    }
    bool checkPowersOfThree(int n) {
        return solve(n , 0);
    }
};