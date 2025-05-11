class Solution {
public:
    int ans = INT_MAX;
    void solve(int i , vector <int> &cookie , vector <int> &child){
        if(i == cookie.size()){
            ans = min(ans , *max_element(child.begin() , child.end()));
            return ;
        }
        for(int j = 0 ; j < child.size() ; j++){
            child[j] += cookie[i];
            solve(i + 1 , cookie , child);
            child[j] -= cookie[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector <int> child(k);
        solve(0 , cookies , child);
        return ans;
    }
};