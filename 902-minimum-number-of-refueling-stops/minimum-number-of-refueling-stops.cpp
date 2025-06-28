class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue <int> gas;
        int ans , n = stations.size() , i = 0;
        for(ans = 0 ; startFuel < target ; ans++){
            while(i < n and startFuel >= stations[i][0])
                gas.push(stations[i++][1]);
            if(gas.empty())
                return -1;
            startFuel += gas.top(); gas.pop();
        }
        return ans;
    }
};

/*
Have to reach target with min fuel stops.
sort stations by positions.
while startFuel >= nextPosition of station we can reach that stations,
if startFuel >= target we stop refilling tank.
Above greedy approach don't work. Should have known better.
Knapsack DP?
Problem can be solved by using a simple pq. Even though the positions are sorted in input, I sorted it again, I should have solved it on my own.
Just, keep going to max limit with current gas and take gas from the stations that has most gas.
*/