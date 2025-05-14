class Solution {
public:
    int minOperations(vector<int>& nums) {
        int one = 0 , two = 0; // number of each operation
        for(int &N : nums){
            int div = 0;
            while(N > 0){
                if(N % 2)
                    N-- , one++;
                else N /= 2 , div++;
            }
            two = max(two , div);
        }
        return one + two;
    }
};
/*
In one operation one number can be incremented or all numbers can be doubled. 
Flip the question and reduce nums to arr.
For a number in nums , if it's odd , we have no choice but to decrease it (number 1 operation)
Otherwise to minimize operation we can divide by two. Since 2nd operation can be distributed among all numbers maximum number's 2nd operation should be sufficient.
*/