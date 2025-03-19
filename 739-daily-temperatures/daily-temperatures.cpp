class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack <int> st;
        int n = temp.size();
        vector <int> ans(n);
        for(int i = 0 ; i < n ; i++){
            while(not st.empty() and temp[st.top()] < temp[i])
                ans[st.top()] = i - st.top() , st.pop();
            st.push(i);
        }
        return ans;
    }
};

/*
stack stores temperature in decreasing order. If a warmer temp is encountered, for every lesser temp in stack, answer is calculated.
If for a temp warmer temp doesn't exist in the futures, it is required to put a 0 in it's place. They will be left out in the stack, and by default assigned 0.
*/