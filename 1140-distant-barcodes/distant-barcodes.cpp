class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map <int,int> freq;
        for(int &i : barcodes)
            freq[i]++;
        vector <pair<int,int>> v;
        for(auto it : freq)
            v.push_back({it.second , it.first});
        sort(v.rbegin() , v.rend());
        int i = 0 , n = barcodes.size();
        for(auto &[cnt , val] : v){
            while(cnt > 0){
                barcodes[i] = val;
                i += 2;
                if(i >= n)
                    i = 1;
                cnt--;
            }
        }
        return barcodes;
    }
};