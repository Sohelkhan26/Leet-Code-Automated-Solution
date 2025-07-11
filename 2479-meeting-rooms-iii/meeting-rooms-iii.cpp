class Solution {
public:
    typedef pair<long long,int> p;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        priority_queue <p , vector<p> , greater<p> > engaged; // {endTime , id}
        priority_queue <int , vector <int> , greater<int> > free; // id
        for(int i = 0 ; i < n ; i++)
            free.push(i);
        vector <int> freq(n);
        for(auto &m : meetings){
            int s = m[0] , e = m[1];
            while(not engaged.empty() and engaged.top().first <= s) // these room became free before the start of this meeting
                free.push(engaged.top().second) , engaged.pop();
            if(not free.empty()){ // if free, use that room
                int id = free.top(); free.pop();
                freq[id]++;
                engaged.push({e , id});
            }else{
                auto [time , id] = engaged.top(); engaged.pop(); // top room will be free first
                freq[id]++;
                engaged.push({time + (e - s) , id}); // add current meeting duration too. 
            }
        }
        int maxF = *max_element(freq.begin() , freq.end());
        for(int i = 0 ; i < n ; i++)
            if(freq[i] == maxF)
                return i;
        return -1;
    }
};

/*
Simulation problem. Do what the problem asks to do. 
n rooms and some meetings.
each meetings held in unused room, if multiple, use the one with smallest number.
if none, when one becomes free, meetings with smallest start time wil be held
return the room that helds highest meetings, if multiple return the one with smallest number
*/