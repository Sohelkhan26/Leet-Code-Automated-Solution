/*
প্রবলেমে বলা আছে শুধু adjacent element swap করা যাবে। কিন্তু যেহেতু অসংখ্যবার করা যাবে তাই প্রথম কন্ডিশনের কোন গুরুত্ব নাই। যেকোন সংখ্যকবার swap করে যেকোন এলিমেন্ট কে যেকোনো জায়গায় নেওয়া যাবে। নেওয়ার পর দুইটা করে -ve এলিমেন্ট কে একগ্রুপ করে অপারেশন চলালে সব পজিটিভ হয় যাবে। কিন্তু পুরো ম্যাট্রিক্সে যদি বেজোড় সংখ্যক -ve element থাকে তাহলে শেষ পর্যন্ত একটা -ve ই থেকে যাবে। 
*/
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0 , minValue = INT_MAX , negative = 0;
        for(auto it : matrix){
            for(int i : it){
                if(i < 0) 
                    negative++;
                ans += abs(i);
                minValue = abs(i) < minValue ? abs(i) : minValue;
            }
        }
        if(negative % 2)
            ans -= 2 * minValue; // because we added it once
        return ans;
    }
};