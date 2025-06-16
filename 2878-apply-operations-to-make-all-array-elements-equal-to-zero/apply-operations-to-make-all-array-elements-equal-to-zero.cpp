class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size() , prefix = 0;
        vector <int> residue(n); 
        for(int i = 0 ; i < n ; i++){
            if(prefix > nums[i])
                return false;
            residue[i] = nums[i] - prefix;
            prefix += residue[i];
            if((i + 1) >= k) // i -> 0 indexed so + 1
                prefix -= residue[(i + 1) - k]; // window size == k decrease window size for next iteration
        }
        return prefix == 0;
    }
};

/*
make all nums[i] to exactly 0 by selecting a subarray size of k and adding -1 to all.
seems like a monotonic non-increasing/decreasing problem. 
There can't be any dip in the nums. n % k != 0 -> false
every k length window should follow monotonic nature. 
window = [i , i + 1 , i + 2 ... k]
all element [i + 1 .. k] should be subtracted by [i] first element.
If Any element has residue , next k elements should be subtracted by that residue. 
residue effects k size window , so we have to store it seperately.
It may not seem intuitive but residue has prefix sum effect. 
*/