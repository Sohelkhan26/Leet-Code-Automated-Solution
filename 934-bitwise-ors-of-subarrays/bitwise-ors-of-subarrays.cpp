class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set <int> prev , curr , temp;
        for(int i : arr){
            temp = {i}; // Single value is a subarray itself.
            for(int j : curr) // curr stores ORs of subarrays ending at current index
                temp.insert(i | j); // extending all prev subarray to include current element
            curr = temp; // update current ORs
            for(int j : curr)
                prev.insert(j);
        }
        return prev.size();// stores all distinct ORs
    }
};

/*
Very intersting problem. There is not much to observe from the problem statement.
Only required to find distinct OR values. This is the biggest hint.
If one bit is set , it will never be unset. So there could be 32 combination at most.Because there are 32 bits in an int data type.
So, optimized brute force method is taken. Calculate all Subarrays, but since we are to find distinct OR values, we store it into a set. That way all duplicate subarray don't get counted multiple times.
*/