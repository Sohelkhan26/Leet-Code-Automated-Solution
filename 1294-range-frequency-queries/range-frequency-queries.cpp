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

/*
upper_bound return pointer to value > target.
lower_bound returns pointer to value >= target.
we could have used upper_bound( , right) - lower_bound( , left)
যেহেতু upper_bound টারগেটের চাইতে বড় ভ্যালু পয়েন্ট করবে সবসময় upper_bound( , left - 1) এ left যদি উপস্থিত থাকে তাহলেও সমস্যা নাই , না থাকলেও সমস্যা নাই। 
*/