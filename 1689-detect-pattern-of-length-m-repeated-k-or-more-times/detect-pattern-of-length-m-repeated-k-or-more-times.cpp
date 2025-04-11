class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size() , count = 0;
        for(int i = 0 ; i + m < n ; i++){
            if(arr[i] != arr[i + m]) // ensure pattern repeats consecutively.
                count = 0; // Even if the second element in the pattern doesn't match, count will be reset to 0
            count += (arr[i] == arr[i + m]);
            if(count == (k - 1) * m) // we assumed one pattern and tried to match other element with it. That's why k - 1.
                return true;
        }
        return false;
    }
};

/*
কি উলটাপালটা প্রবলেম রে বাবা। কয়েকটা জিনিস ক্লিয়ার করতে হবেঃ
সাব এরে পরপর k বার repeat হতে হবে। 
arr = [1 , 2 , 3 , 4, 1 , 2] m = 2 , k = 2 should return false.
Because although pattern [1 , 2] is repeated 2 times but not consecutively.
The solution above is taken from someone else. But this is so elegent.
The same line in the inside the if condition and for increasing count is so elegent.
*/