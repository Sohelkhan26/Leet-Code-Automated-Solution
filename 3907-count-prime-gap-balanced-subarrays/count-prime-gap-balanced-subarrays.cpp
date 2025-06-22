class Solution { 
public: 
    const int MAXN = 100000;
    
    int primeSubarray(vector<int>& nums, int k) {
        vector<bool> prime(MAXN + 1 , true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= MAXN; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= MAXN; j += i) {
                    prime[j] = false;
                }
            }
        }
        int ans = 0 , secondRecent = -1, recent = -1 , n = nums.size();

        multiset<int> window;

        for(int left = 0 , right = 0 ; right < n ; right++){
            // if prime --> insert in the set
            if(prime[nums[right]]){
                secondRecent = recent;
                recent = right;
                window.insert(nums[right]);
            }

            // shrink window if difference > k
            while(not window.empty() and *window.rbegin() - *window.begin() > k){
                if(prime[nums[left]]){
                    window.erase(window.find(nums[left]));
                }
                left++;
            } 

            if(window.size() >= 2){
                ans += (secondRecent - left + 1);
            } 
        }
        return ans;
    }
};