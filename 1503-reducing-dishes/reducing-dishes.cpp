class Solution {
public:
    int maxSatisfaction(vector<int>& nums) {
        sort(nums.rbegin() , nums.rend());
        int ans = 0 , dishes = 0;
        for(int i : nums){
            dishes += i;
            if(dishes > 0)
                ans += dishes;
            else break;
        }
        return ans;
    }
};
/*
Similar to kadene's algo. Only take a dish if it increases the co-efficient. How do we find out if a dish increases the co-efficient?
মজাদার dish সবার পরে রান্না করতে হবে। তাহলে এর সাথে বেশী time গুন হয়ে বেশী answer বৃদ্ধি করবে। 
যেসব dish এর satisfaction >= 0 সবগুলাই রান্না করতে হবে। < 0 হলে দুইটা কেসঃ
১। এটা অবশ্যই সবার প্রথমে রান্না করতে হবে। ফলে এর পরে যেগুলা রান্না করা হবে সবগুলার সাথে এক্সট্রা ১ করে গুন হবে। এক্সট্রা গুন হওয়ার কারনে এনসার এ যা কন্ট্রিবিউট করবে তার চাইতে যদি (-ve satisfaction) ওয়ালা dish যদি বেশী বিয়োগ করে ফেলে তাহলে তো রান্না করা যাবে না। 
-1 2 5
এখানে -১ রান্না করা যাবে কারণ এটা রান্না করলে ans += (6) হবে এবং এটার কারনে 1 বিয়োগ হবে। তাই এট লাভজনক। কিন্তু -15 2 5 এর ক্ষেত্রে -15 রান্না করা লাভজনক না। ans += (6) ans -= 15. ans += 6 হওয়ার কারণ Everytime we add a new dish to the menu list,
all dishes on the menu list will be cooked one time unit later,
so the result += total satisfaction on the list (ans += dishes in my code)
*/