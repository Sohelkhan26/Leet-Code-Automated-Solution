class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size() , group = 0; 
        vector <int> ans(n);
        for(int i = 0 ; i < n ; i++){
            char c = s[i];
            if(c == '(')
                ans[i] = ++group % 2;
            else // ')'
                ans[i] = group-- % 2; // should match previous '(' bracket's group
        }
        return ans;
    }
};

/*
Such a long description.
Given a string , split it into two disjoint set such that
max(depth(a) , depth(b)) is minimum

a and b must be balanced. In short: there exists 1 ) for each (
depth("") = 0
depth(a + b) = max(depth(a) , depth(b))
depth("(a)") = 1 + depth(a)

Note: input is balanced

ans[i] = 0 if it's in a otherwise 1
I think it's a trick problem.
order like this : ()()() try to reduce nested brackets like this : ((()))
It's always possible to arrange a = all () and b = all ()
if nested input: ((())) each new layer need to go to different group. a -> b -> a

Disappointing. I figured out the solution but couldn't implement it. Used stack.
Take turn when nested brackets. and they should be symmetric
0,1,0,0,1,0
( ( ( ) ) )
*/