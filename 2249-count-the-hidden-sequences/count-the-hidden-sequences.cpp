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

✅ Fixing x = 0: Why It's Safe
Suppose you assume x = 0 (i.e., the first element of the hidden array is 0).

Then your hidden array becomes just the prefix sum array:

hidden = [0, d1, d1 + d2, ..., total sum]
Let’s call this base sequence S.

Now, any actual valid hidden array is just a shifted version of S:

hidden_actual[i] = S[i] + x
So the shape of the array is fixed — only the vertical shift (x) varies.
To ensure the shifted array lies within [lower, upper], you want:
lower ≤ x + minVal
upper ≥ x + maxVal

Solving:

x ≥ lower - minVal
x ≤ upper - maxVal

So x must lie in this range: [lower - minVal, upper - maxVal]
And total valid x values = upper - maxVal - (lower - minVal) + 1
*/