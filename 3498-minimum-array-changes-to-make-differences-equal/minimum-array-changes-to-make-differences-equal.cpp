class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size() , ans = INT_MAX;    
        unordered_map <int,int> freq;
        vector <int> v;
        for(int i = 0 ; i < n / 2 ; i++){
            int a = nums[i] , b = nums[n - i - 1] , diff = abs(a - b);
            freq[diff]++;
            int threshold = max({max(a , b) , abs(a - k) , abs(k - b)});
            v.push_back(threshold); 
        } 
        sort(v.begin() , v.end());
        n /= 2;
        for(int x = 0 ; x <= k ; x++){
            
            int one = n - freq[x]; // freq[x] is original diff without changing any element , n is pair count
            int two = lower_bound(v.begin() , v.end() , x) - v.begin(); // maxDiff < x will require one more change in element.
            ans = min(ans , one + two);
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