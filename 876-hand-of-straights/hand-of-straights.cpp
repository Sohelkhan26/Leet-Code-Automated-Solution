class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0)
            return false;
        map <int,int> freq;
        for(int i : hand)
            freq[i]++;
        while(not freq.empty()){
            int grpLeader = freq.begin() -> first;
            for(int i = 0 ; i < groupSize ; i++){
                if(not freq[grpLeader + i])
                    return false;
                if(--freq[grpLeader + i] == 0)
                    freq.erase(grpLeader + i);
            }
        }
        return true;
    }
};