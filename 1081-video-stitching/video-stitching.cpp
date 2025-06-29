class Solution {
public: 
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin() , clips.end());
        int ans = 0 , n = clips.size();
        for(int start = 0 , end = 0 , i = 0 ; end < time ; ){
            while(i < n and clips[i][0] <= start)
                end = max(end , clips[i++][1]);
            if(start == end)
                return -1;
            start = end;
            ans++;
        }
        return ans;
    }
};

/*
return the min number of intervals needed to cover [0..time](they may overlap)
what's the play? Greedy?
sort by start?
sorting by time covered won't work, they might cover the same interval over and over.
I have a feeling Greedy will work, but how to implement it?
I am terrified of DP.
Actually I was right. Greedy does work. So close. Don't fret. There is always a next time.
Keep track of current starting position. For each iteration,check all overlapping intervals, and pick the one that advance our starting position the furthest.
If clips[i][0] < start that don't matter, overlapping is allowed.
*/