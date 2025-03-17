class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector <int> freq(501);
        for(int i : nums)
            freq[i]++;
        for(int i = 0 ; i < freq.size() ; i++)
            if(freq[i] % 2)
                return false;
        return true;
    }
};