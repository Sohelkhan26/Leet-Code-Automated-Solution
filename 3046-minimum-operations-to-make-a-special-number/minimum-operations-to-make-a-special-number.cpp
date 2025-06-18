class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size() , ans = n;
        set <string> div = {"00" , "25" , "50" , "75"};
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = i - 1 ; j >= 0 ; j--){
                string target = string(1 , num[j]) + string(1 , num[i]);
                if(div.contains(target))
                    ans = min(ans , n - j - 2);
            }
            if(num[i] == '0') // num has only one 0 i.e : 10 , 3440
                ans = min(ans , n - 1);
        }
        return ans;
    }
};