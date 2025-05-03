class Solution {
public:
    int minimumDeletions(string s) {
        stack <char> st;
        int ans = 0;
        for(char &c : s){
            if(not st.empty() and st.top() == 'b' and c == 'a')
                st.pop() , ans++;
            else st.push(c);
        }
        return ans;
    }
};

/*
I had a feeling this might be a stack problem.
*/