class Solution {
public:
    int solve(int i , vector<bitset<26>> &nums , bitset <26> curr){
        if(i == nums.size())
            return curr.count();
        int len = 0;
        if(not (curr & nums[i]).any())
            len = solve(i + 1 , nums , curr | nums[i]);
        len = max(len , solve(i + 1 , nums , curr));
        return len;
    }
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> unique;
        for(string &s : arr){
            bitset<26> mask;
            for(char &c : s)
                mask.set(c - 'a');
            if(mask.count() == s.size())
                unique.push_back(mask);
        }
        return solve(0 , unique , bitset<26> ());
    }
};

/*
Find the maximum length of an string s , that can be formed by subsequence of arr. String s should have unique characters.
If any string from arr has duplicates, it can't be added as an subsequence to the answer string.
Maxium length of answer string is 26, cause there is 26 unique characters in english alphabet.
To leverage uniqueness of strings , we use bitset.
Every string is represented as bitset, initially answer string is 0(no unique chars). For every string in arr, we can either include it or not include it in the answer string. If another string & answer string == 0,
it means, no duplicate char in between them. In the end we return the total set-bit-count of the answer string.
*/