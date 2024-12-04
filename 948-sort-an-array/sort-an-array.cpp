class Solution {
public:
    void Merge(int left , int mid , int right , vector<int> &nums)
    {
        int n = mid - left + 1 , m = right - mid , i , j;
        int Left[n] ,  Right[m];
        for(i = 0 ; i < n ; i++)
        Left[i] = nums[left + i];
        for(i = 0 ; i < m ; i++)
        Right[i] = nums[mid + 1 + i];
        int k = left;
        i = 0 , j = 0;
        while(i < n && j < m)
        {
            if(Left[i] < Right[j])
            nums[k++] = Left[i++];
            else nums[k++] = Right[j++];
        }
        for(; j < m ; j++)
            nums[k++] = Right[j];
        for(;i < n ; i++)
            nums[k++] = Left[i];
    }
    void mergesort(int low , int high , vector<int> &nums)
    {
        if(low < high)
        {
            int mid = low + (high - low) / 2;
            mergesort(low , mid , nums);
            mergesort(mid + 1 , high , nums);
            Merge(low , mid , high  , nums);
        }
        else return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(0 , nums.size() - 1 , nums);
        return nums;
    }
};