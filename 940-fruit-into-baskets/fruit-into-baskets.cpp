class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() , ans = 0 , count = 0;
        unordered_map <int,int> freq;
        for(int left = 0 , right = 0 ; right < n ; right++){
            freq[fruits[right]]++ , count++;
            if(freq.size() > 2){
                if(--freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++ , count--;
            }
            if(freq.size() <= 2)
                ans = max(ans , count);
        }
        return ans;
    }
};