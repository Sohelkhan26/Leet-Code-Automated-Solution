class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
         // Map to store changes in color sum at each point.
        // Using long long to avoid overflow from color sums.
        map<int, long long> line; 
        for (auto it : seg) { 
            line[it[0]] += it[2]; 
            line[it[1]] -= it[2];
        }

        int prev = -1;  
        vector<vector<long long>> ans; 
        long long sum = 0; // Current active color sum (represents the mixed color of current segment)
 
        for (auto& [curr, color] : line) { 
            // If we have an active color (sum != 0), store the painted segment [prev, curr)
            if (sum != 0 && prev != -1)
                ans.push_back({prev, curr, sum}); 
            sum += color; 
            prev = curr;
        }

        return ans;
    }
};
/*
Line Sweep. Output : Overlapping intervals with sum of their color.
Sum start and end of an interval with corresponding color. If some part of a interval overlap with another one, their color will be summed up.
So, as we are only start and end of an interval, and no way to decide if it's a start or end , as soon as we hit a new key in map, that's supposed to be ending interval. prev is used to indicate the starting of the first interval. Usage of map ensures sorted order of intervals.
*/