class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack <int> st;
        int n = arr.size() , mod = 1e9 + 7 , ans = 0;
        for(int i = 0 ; i < n ; i++){
            while(not st.empty() and arr[st.top()] > arr[i]){ // since current element is smaller then top, it's the bottle neck. expanding the subarray won't result in a minimum value other than current element.
                int maxIdx = st.top(); st.pop();
                int right = i - maxIdx; // right don't include arr[maxIdx]
                int left = st.empty() ? maxIdx + 1 : maxIdx - st.top(); // extra + 1 for arr[maxIdx]
                ans = (ans + 1LL * arr[maxIdx] * left * right) % mod;
            }
            st.push(i);
        }
        while(not st.empty()){
            int maxIdx = st.top(); st.pop();
            int right = n - maxIdx; 
            int left = st.empty() ? maxIdx + 1 : maxIdx - st.top();
            ans = (ans + 1LL * arr[maxIdx] * left * right) % mod;
        }
        return ans;
    }
};

/*
There are Some complexity. 
Simply traversing the array twice (once reversed) won't calculate the result correctly.
If the min element is in the middle of subarray it will create some extra valid subarray. Valid subarray is an subarray where the current element is the minimum.
i.e : 13 , 2 , 3 , 5
value = 2 will create 2 * 2 valid subarray.(dry run yourself)

mono-inc stack is needed . Min value is the bottleneck. 
When a min Value is encountered, all previous subarray can only be extended until now. So, for each previous elements calculate it's contribution.
Calculating contribution is the most tricky part. Can be broken into two parts
left and right contribution. Since stack is mono-increasing, top() element can be extended to left only until previous top() and can be extended to the right until current minimum element.
*/