class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size() , discard = (n * 5) / 100 , left = 0 , right = n;
        for(int i = 0 ; i < discard ; i++)
            left++ , right--;
        return accumulate(arr.begin() + left , arr.begin() + right , 0.0) / (right - left);
    }
};