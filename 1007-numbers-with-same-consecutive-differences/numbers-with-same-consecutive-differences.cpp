class Solution {
public:
    vector <int> ans;
    void solve(int n , int k , int lastDigit , int num){
        if(n == 0){
            ans.push_back(num);
            return;
        }
        for(int i = 0 ; i < 10 ; i++)
            if(abs(i - lastDigit) == k)
                solve(n - 1 , k , i , num * 10 + i);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i = 1 ; i < 10 ; i++) // no point in starting from 0 caus it will have n - 1 digits for sure
            solve(n - 1 , k , i , i);
        return ans;
    }
};

/*
Whatever the last digit may be only one digit in the range [0 , 9] will satisfy
currDigt + lastDigit <= 9
At first I thought of this problem in a more complicated manner. If last Digit is greater than k we should subtract , otherwise add etc.
*/