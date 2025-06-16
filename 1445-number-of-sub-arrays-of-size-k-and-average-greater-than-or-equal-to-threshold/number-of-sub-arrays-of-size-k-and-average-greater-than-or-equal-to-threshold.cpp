class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size() , window = 0 , ans = 0;
        for(int left = 0 , right = 0 ; right < n ; right++){
            window += arr[right];
            if(right - left + 1 > k) // size exceeds k
                window -= arr[left++];
            if(right - left + 1 == k and window >= k * threshold) // subarray size k and average >= threshold
                ans++;
        }
        return ans;
    }
};


/*
count-number-of-subarrays whose average >= threshold
can't generate every subarray. 
I think sliding window won't work. We need window of exactly k size.
want subarray sum = k * threshold
and subarray size = k 
Sliding window actually works. maintain exactly k size window.
if size exceeds k shrink the window.
*/