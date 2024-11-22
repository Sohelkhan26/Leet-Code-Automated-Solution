class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = 0 , win = 0 , n = arr.size();
        for(int i = 1 ; i < n ; i++){
            if(arr[winner] < arr[i]){
                winner = i;
                win = 0;
            }
            if(++win == k)break;
        }        
        return arr[winner];
    }
};