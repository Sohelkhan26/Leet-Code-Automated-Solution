class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MAX , change = 0; 
        map <int,int> line;
        for(int i = 0 ; i < n / 2 ; i++){
            int a = nums[i] , b = nums[n - i - 1] , diff = abs(a - b); 
            int threshold = max({max(a , b) , abs(a - k) , abs(k - b)});
            line[0] += 1; // 0 <= X < diff = need 1 change
            line[diff] -= 1; // 0 <= X < diff = need 1 change
            line[diff + 1] += 1; // diff < X <= threshold , need 1 change
            line[threshold + 1] += 1; // diff < X <= threshold , need 1 change
            // X > threshold need 2 change , which we don't need.
        } 
        for(int x = 0 ; x <= k ; x++){
            change += line[x];
            ans = min(ans , change);
        }
        return ans;
    }
};

/*
n even, can change every element in array to [0..k] such that abs(nums[n - i - 1] - nums[i]) is equal to some constant value x for all i. return min operation.
any element can be in range [0..k]
diff of a pair can be at most max(0 - b , a - 0 , k - b , a - k) we can achieve this diff(which is maximum) by changing one element only.
if we want to make this diff more than this, we will require one more operation(change both a & b)

*/