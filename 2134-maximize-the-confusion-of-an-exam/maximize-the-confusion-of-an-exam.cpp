class Solution {
public:
    int maxConsecutiveAnswers(string s , int k) {
        auto solve = [&](char c){
            int count = 0 , ans = 0 , n = s.size();
            for(int left = 0 , right = 0 ; right < n ; right++){
                count += (s[right] == c);
                while(count > k)
                    count -= (s[left++] == c);
                ans = max(ans , right - left + 1);
            }
            return ans;
        };
        return max(solve('T') , solve('F'));
    }
};
