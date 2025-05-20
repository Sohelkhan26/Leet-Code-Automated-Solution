class Solution {
public:
    int getMinSwaps(string num, int k) {
        string origin = num;
        while(k--)
            next_permutation(num.begin() , num.end());
        int n = num.size() , ans = 0 , i = 0 , j = 0;
        while(i < n){
            while(i < n and origin[i] == num[i])
                i++;
            j = i;
            while(j < n and origin[i] != num[j])
                j++;
            while(i < j){
                swap(num[j] , num[j - 1]);
                j--;ans++;
            }
            i++;
        }
        return ans;
    }
};

/*
find min "adjacent" digit swaps to find k'th smallest string that is a permutaton of num and is greater than num
We can't just swap any two digits, only adjacent, what does it imply?
*/