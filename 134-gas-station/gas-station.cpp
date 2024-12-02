class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , totalGas = 0 , tank = 0 , start = 0;
        for(int i = 0 ; i < n ; i++){
            if((tank = tank + gas[i] - cost[i]) < 0){
                start = i + 1;
                totalGas += tank;
                tank = 0;
            }
        }
        totalGas += tank;
        return totalGas < 0 ? -1 : start;
    }
};
/*
Given gas and cost of each station Determine if it's possible to visit all the gas stations.
If possible find out the starting index.
If we substract cost[i] from gas[i] we find out the extra gas. If After visiting all the gas station there is zero or some gas left we can visit all the gas stations otherwise return -1.
Now we have to find out the starting point. 
কোন স্টেশনে যদি -ve পরিমাণ গ্যাস থাকে তার মানে অইটা থেকে আমরা যাত্রা শুরু করতে পারবো না, যদি করি তাহলে গ্যাস শেষ হয়ে যাবে। কারন এই স্টেশন থেকে পরের স্টেশনে যেতে হলে আগের কোন স্টেশন থেকে extra gas লাগবে। তাই কোন স্টেশনে যদি -ve গ্যাস হয় তাহলে আমরা পরের স্টেশন থেকে যাত্রা শুরু করবো। 
*/