class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map <int,int> freq;
        for(int &i : arr)
            freq[i]++;
        priority_queue <int , vector<int> , greater<int> > pq;
        for(auto &[key , count] : freq)
            pq.push(count);
        while(not pq.empty()){
            if(pq.top() > k)
                break;
            k -= pq.top(); pq.pop();
        }
        return pq.size();
    }
};