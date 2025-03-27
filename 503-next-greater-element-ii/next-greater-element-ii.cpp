class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        int n = nums.size();
        for(int i = n - 1 ; i >= 0 ; i--)
            st.push(nums[i]);
        vector <int> ans(n);
        for(int i = n - 1 ; i >= 0 ; i--){
            while(not st.empty() and st.top() <= nums[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};