class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& change) {
        int n = nums.size() , m = change.size();
        int low = 0 , high = m , mid , ans = -1;
        auto possible = [&](int mid){
            int op = 0;
            unordered_map <int,int> last;
            for(int i = 0 ; i < mid ; i++)
                last[change[i]] = i;
            if(last.size() < n) // change.size() should be at least nums.size()
                return false;
            for(int i = 0 ; i < mid ; i++){
                if(i == last[change[i]]){
                    if(op < nums[change[i] - 1])
                        return false;
                    op -= nums[change[i] - 1]; // use op to decrement other elements.
                }else op++;
            }
            return true;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(possible(mid))
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};

/*
query -> change -> changeIndices
n elements. and a query array(1 indexed)
at i'th time, you can either:
1. decrement any element
2. mark nums[change[i]] to 0
Some things are clear:
all the indices of nums, should be present in the query at least once.
At least sum(nums) + nums.size() time is needed. answer in range [n , sum(nums) + n] 
we can't manually decrement nums[i] cause lim <= 1e9 But m is short 2000
actually we can. even though it may seem we can't.

It's combination of greedy and binary search.
We try to mark a index 'i' at last possible moment i.e: last occurance in query array. Before that index, we use decrment operation. If the decrement operation is not enough to make that element zero by the time we arrive at last occurance of that index, we can't mark it. If decrement operation is greater, we can use it for other elements.

Though the code is short, It packs a punch.
*/