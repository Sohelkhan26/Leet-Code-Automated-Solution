class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0 , n = ages.size();
        sort(ages.begin() , ages.end());
        for(int i = 0 ; i < n ; i++){
            int lower = (int)(upper_bound(ages.begin() , ages.end() , ages[i] * 0.5 + 7) - ages.begin());
            int upper = upper_bound(ages.begin() , ages.end() , ages[i]) - ages.begin();
            ans += max(upper - lower - 1 , 0);
        }
        return ans;
    }
};

/*
x = own 
y = other
own can send friend request to other's if they are in the range (0.5 * own + 7 , own] lower range is non-inclusive, upper range is inclusive. Third condition and second is the same.
problem asks us to find total friend requests made. In other words, pairs that fullfill the above requirement.
Own can't send friend request to older others. So, get the idea of sorting.
And to satisfy the condition, binary search comes into play.
upper variable finds out people with same ages. but own can't send friend request to himself, 1 is subtracted.
Note: upper_bound retreives the first element that is strictly greater than target.
*/