class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() , ans = 0;
        for(int left = 0 , right = n - 1 ; left < right ; ){
            ans = max(ans , (right - left) * min(height[left] , height[right]));
            if(height[left] > height[right])
                right--;
            else left++;
        }
        return ans;
    }
};