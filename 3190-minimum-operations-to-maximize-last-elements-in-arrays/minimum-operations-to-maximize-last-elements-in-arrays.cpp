class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        // swap -> for case n - 1 position was swapped
        // dont -> n - 1 position not swapped
        int n = a.size() , swap = 1 , dont = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            if(max(a[i] , b[i]) > max(a[n - 1] , b[n - 1])) // swapping don't help
                return -1;
            if(min(a[i] , b[i]) > min(a[n - 1] , b[n - 1]))
                return -1;
            if(a[i] > a[n - 1] or b[i] > b[n - 1])
                dont++;
            if(a[i] > b[n - 1] or b[i] > a[n - 1])
                swap++;
        }
        return min(swap , dont);
    }
};