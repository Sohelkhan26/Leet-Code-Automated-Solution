class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int start = 0 , minVal = 0 , maxVal = 0 , ans = 0;
        for(int &d : differences){
            start += d;
            minVal = min(minVal , start);
            maxVal = max(maxVal , start);
            ans = (upper - maxVal) - (lower - minVal) + 1;
            if(ans <= 0)
                return 0;
        }
        return (upper - maxVal) - (lower - minVal) + 1;
    }
};

/*
hidden = hidden sequence
If we add or substract some constant X from each element, difference array stays the same.
L <= hidden[i] + X <= U for all index i.
Suppose, minVal , maxVal is min and max element of our hidden sequence.
minVal + X >= L
maxVal + X <= U
So, X should be in the range [L - minVal , U - maxVal]
For every shift in the above range, we can get a new hidden sequence. So, total number of distinct hidden sequence = (U - maxVal) - (L - minVal) + 1


The highest peak of the graph can be between (upper - max) so count += (upper - max) and deepest valley can be between (min - lower) so count += (min - lower) and +1 as one of the value got subtracted twice

ans = (upper - max) + (min - lower) + 1
*/