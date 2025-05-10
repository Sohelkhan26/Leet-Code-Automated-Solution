class Solution {
public:
    int dp[10][10][2];
    int solve(string &s , int i , bool edge , int count){
        if(i == s.size())
            return count;
        if(dp[i][count][edge] != -1)
            return dp[i][count][edge];
        int limit = (edge ? s[i] - '0' : 9) , ans = 0; // we're interested in finding numbers less than right bound or string s. So, if we place any number > s[i] then whatever we place next , the resulting number will always be > right bound. Even if we place s[i] in this index, then next digit can't be larger than s[i + 1]. Next digit <= s[i + 1]. If we place digit < s[i] , then whatever we place next , will form smaller number than right bound.
        for(int n = 0 ; n <= limit ; n++){// n refers to the digit placed in this index.
            bool newEdge = (edge & (n == (s[i] - '0')));// current digit touched the edge only if, previous and current digit both touched edge
            int newCount = count + (n == 1); // we are interested in no-of 1 in our number
            ans += solve(s , i + 1 , newEdge , newCount);
        }
        return dp[i][count][edge] = ans;
    }
    int countDigitOne(int n) {
        memset(dp , -1 , sizeof(dp));
        string s = to_string(n);
        return solve(s , 0 , 1 , 0);
    }
};

/*
Digit Dp is calculated by a certain variation of prefix sum. 
solve(R) - solve(L - 1) like this.
If digit in every place is constrained. If L = 3545 , R = 7643 
digit in first position is constrained by the edge = 3
If we place 3 in first position , digit placed on upcoming indices will depend on the edge (digit >= 6 can't be placed on 2nd index) , so 3 is referred to as edge(constraint). Common parameter of digit dp is 2, 1st one indicating index , second one edge. Third one varies problem to problem.
In this case, we are counting 1 in our number. log(10 ^ 9) atmost 10 digit, so atmost 10 one's in the number.
Total Subproblem = 10 * 10 * 2 (index , count , edge) = 200

*/