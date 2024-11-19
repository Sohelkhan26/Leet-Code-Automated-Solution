/*
O(n ^ 2) -> TLE
প্রতি পজিশনের জন্য কতগুলা pair এ ডিজিট সমান না সেটা বের করতে হবে। 
আমরা যদি প্রতি নাম্বার এর জন্য , প্রতি পজিশনে ডিজিটের ফ্রিকোয়েন্সি সেভ করে রাখতে পারি তাহলে ক্যালকুলেশন ইজি হবে। 
freq এর রো হলো পজিশন , কলাম হলো প্রতি ডিজিটের ফ্রিকোয়েন্সি। 
*/
class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        vector<vector<int>> freq(10 , vector<int> (10));
        int n = nums.size();
        for(int i : nums)
            for(int j = 0 ; i > 0 ; i /= 10 , j++)
                freq[j][i % 10]++;
        long long ans = 0;
        for(int i = 0 ; i < 10 ; i++)
            for(int j = 0 ; j < 10 ; j++)
                ans += (freq[i][j] * (n * 1LL - freq[i][j]));
        return ans / 2;
    }
};