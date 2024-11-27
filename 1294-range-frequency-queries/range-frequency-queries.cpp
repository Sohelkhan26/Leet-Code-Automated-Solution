class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> indices;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0 ; i < arr.size() ; i++)
            indices[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        return upper_bound(indices[value].begin() , indices[value].end() , right) - upper_bound(indices[value].begin() , indices[value].end() , left - 1);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */