class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size() , low = 0 , high = m - 1 , mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            int maxValue = -1 , index = -1;
            for(int i = 0 ; i < n ; i++)
                if(mat[i][mid] > maxValue)
                    maxValue = mat[i][mid] , index = i;
            int leftValue = mid - 1 >= 0 ? mat[index][mid - 1] : -1;
            int rightValue = mid + 1 < m ? mat[index][mid + 1]  : -1;
            if(leftValue < mat[index][mid] and mat[index][mid] > rightValue)
                return {index , mid};
            else if(mat[index][mid] < leftValue)
                high = mid - 1;
            else low = mid + 1;
        }
        return {-1 , -1};
    }
};