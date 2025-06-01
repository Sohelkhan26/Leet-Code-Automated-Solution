class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps = {startTime[0]};
        int n = startTime.size() , ans = 0 , window = 0;
        for(int i = 1 ; i < n ; i++)
            gaps.emplace_back(startTime[i] - endTime[i - 1]);
        gaps.emplace_back(eventTime - endTime[n - 1]);
        for(int left = 0 , right = 0 ; right < gaps.size() ; right++){
            window += gaps[right];
            if(right - left + 1 > k + 1)
                window -= gaps[left++];
            ans = max(ans , window);
        }
        return ans;
    }
};

/*
meeting time non-overlapping. 
reschedule on the basis of what?
maximize longest free time. 
if k >= meeting.size() all can be moved to beginning.
if we merge two meeting, their starting time can be either. we can merge 1st with 2nd or 2nd with 1st.
n very high, no brute force.
Biggest hint is have to maintain relative order even after resheduling. Meaning we can't place one meeting in between two meetings, we can either shift backward or forward.
Seems like sliding window. We can reschedule up to k meetings, so we could merge atmost 'k + 1' gaps after scheduling the meetings left or right. 
Shifting a meeting can merge at most 2 gaps. So, k - 1 gaps in between meetings, at most 2 meetings at left and right side (if they don't start at 0 , eventTime), so at most k + 1 gaps can be merged. If our window size exceeds k + 1 , shrink the window.
*/