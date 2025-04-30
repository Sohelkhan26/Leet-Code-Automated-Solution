class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map <int,int> freq;
        vector <int> keys;
        for(int &i : arr)freq[i]++;
        for(auto &[key , _] : freq)
            keys.push_back(key);
        sort(keys.begin() , keys.end() , [&](int a , int b){
            return abs(a) < abs(b);
        });
        for(int k : keys){
            if(freq[k] > freq[k * 2])
                return false;
            freq[k * 2] -= freq[k];
        }
        return true;
    }
};

/*
Quite hard to understand the problem. We have to place numbers in pair so that one number is 2 as the other. Every number belongs to only one pair.
Be greedy. Start from the smallest number "x" and match it with "2 * x". We have to match every occurance of "x" with "2 * x" otherwise return false. Bucause there is no smaller alternative to match with. 
So, freq[x * 2] >= freq[x] is ok
    freq[x * 2] < freq[x] not ok.
Only problem is input contains negative values. They get sorted in opposite manner. So, sort based on absolute value.
*/