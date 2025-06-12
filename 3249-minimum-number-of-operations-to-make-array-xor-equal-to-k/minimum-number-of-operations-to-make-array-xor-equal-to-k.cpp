class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0 ; i < 30 ; i++){
            int bit = 0;
            for(int &n : nums)
                bit ^= ((n >> i) & 1);
            ans += (bit xor ((k >> i) & 1));
        }
        return ans;
    }
};