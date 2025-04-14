class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size() , ans = 0;
        unordered_map <int,int> mp;
        for(int left = 0 , right = 0 ; right < n ; right++){
            mp[fruits[right]]++;
            while(mp.size() > 2 and left < right){
                if(--mp[fruits[left]] == 0)
                    mp.erase(fruits[left]);
                left++;
            }
            ans = max(ans , right - left + 1);
        }        
        return ans;
    }
};
/*

*/