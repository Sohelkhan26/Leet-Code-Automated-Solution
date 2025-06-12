class Solution {
public:
/*
we try to include points closer to the origin. If these points can't be inlcluded later points can't be(cause square size will increase)

*/
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        map <int,multiset<char>> mp;
        int ans = 0 , n = points.size();
        for(int i = 0 ; i < n ; i++)
            mp[max(abs(points[i][0]) , abs(points[i][1]))].insert(s[i]); // to include i'th point, max square size should be max(abs(x) , abs(y)). we have include all points at this square size.
        set <char> square; // contains characters inside the square
        for(auto &[len , st] : mp){
            set <char> curr;
            for(const char c : st){
                if(curr.contains(c) or square.contains(c))
                    return ans;
// we try to include all char 'c' at distance 'len'. if there are duplicate character in this length (or any character has same tag as a character included in the square) we can't include any character in this len.
                else curr.insert(c);
            }
            for(const char c : st)
                ans++ , square.insert(c);
        }
        return ans;
    }
};

/*
square can be infinitely large and contain all the points.
seems like a sliding window. max len 26 after that tag repeats.
when a same tag point is found shrink window. 
area has to be square and contain 0,0
keep track of bottom-left and top-right corner of square.(how to ensure square?)
shrink window while the window has same tag-point 
area need to be square and have side parallel to axes, so, abs(x - y) same for two corner
0,0 need to be center. so, side of the square is max(abs(x) , abs(y)) of the max element of the window.
*/