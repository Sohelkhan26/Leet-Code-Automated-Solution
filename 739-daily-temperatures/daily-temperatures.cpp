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