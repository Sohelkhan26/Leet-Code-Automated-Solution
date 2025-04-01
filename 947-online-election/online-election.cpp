class TopVotedCandidate {
public:
    map <int,int> leadInTime;
    unordered_map<int,int> voteCount;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size() , lead = -1;
        for(int i = 0 ; i < n ; i++){
            lead = ++voteCount[persons[i]] >= voteCount[lead] ? persons[i] : lead;
            leadInTime[times[i]] = lead;
        }
    }
    
    int q(int t) {
        auto p = --leadInTime.upper_bound(t);
        return p -> second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */