class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if(k >= n)
            return max_element(skills.begin() , skills.end()) - skills.begin();
        deque <int> d;
        vector<int> win(n);
        for(int i = 0 ; i < n ; i++)
            d.push_back(i);
        while(true){
            int first = d.front(); d.pop_front();
            int second = d.front(); d.pop_front();
            if(skills[first] > skills[second]){
                win[first]++;
                d.push_front(first);
                d.push_back(second);
            }else{
                win[second]++;
                d.push_front(second);
                d.push_back(first);
            }
            if(win[first] == k)
                return first;
            if(win[second] == k)
                return second;
        }
        return 0;
    }
};