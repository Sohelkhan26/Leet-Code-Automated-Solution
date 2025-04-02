class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size() , m = matrix[0].size() , ans = -1 , low = matrix[0][0] , high = matrix[n - 1][m - 1] , mid;
        auto countLessOrEqual = [&](int mid){
            int less = 0 , column = m - 1;
            for(int row = 0 ; row < n ; row++){
                while(column >= 0 and matrix[row][column] > mid)
                    column--; // we don't need to reset column to m - 1 at every row, because columns are sorted in ascending order and if matrix[row][column] > mid then matrix[row + 1][column] > mid is a must.
                less += (column + 1);
            }
            return less;
        };
        while(low <= high){
            mid = low + (high - low) / 2;
            if(countLessOrEqual(mid) >= k){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        return ans;
    }
};