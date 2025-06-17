class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map <int,vector <int>> freq;
        int n = nums.size() , ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]].push_back(i);
        }
        for(auto &[num , pos] : freq){
            pos.push_back(pos[0] + n); // to account for circular nature
/* explanation:
[ ...... pos[0] ........... pos.back() ..... ]
n is the length of nums.
To simulate a circle, we need the distance between pos[0] and pos[n - 1](wrap around/circular distance) = pos[0] - 0 + (n - 1) - pos.back() + 1
d = pos[0] + (n - 1) - pos.back() + 1
d = pos[0] + n - pos.back()
d = (pos[0] + n) - (pos.back())
(pos.back()) is already in the array. 
*/
            int seconds = 0;
            for(int i = 1 ; i < pos.size() ; i++)
                seconds = max(seconds , (pos[i] - pos[i - 1]) / 2);
            ans = min(ans , seconds);
        }
        return ans;
    }
};

/*
Need keen observation to solve the problem. 
For each index, that number can be replaced by the previous/next element of the original array for all index simultaneously.
Array is circular.
DP is too complex, so I didn't go that way. Unfortunately I could not solve this on my own.
Didn't even come close. If a number appears at i , j then [0..i...j...n]
then the array can be made equal in max(a , b) seconds. 
a = (j - i) / 2
b = {(n - 1 - j) + (i - 0) + 1(0 based indexing)} / 2 
Since the array is circular, we can go the usual way(left->right) or we can wrap around and go (left->right) and take the maximum distance. 
This intuition can be expanded even if the number appears more than twice.
*/