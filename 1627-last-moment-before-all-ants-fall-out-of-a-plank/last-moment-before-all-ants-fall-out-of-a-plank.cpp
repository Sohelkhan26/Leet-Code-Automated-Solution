class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int low = 0 , high = n , mid , ans = n;
        auto check = [&](int time){
            for(int i : left)
                if((i - time) > 0)
                    return false;
            for(int i : right)
                if((i + time < n))
                    return false;
            return true;
        };   
        while(low <= high){
            mid = low + (high - low) / 2;
            if(check(mid))
                ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};