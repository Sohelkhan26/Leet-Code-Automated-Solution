class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size() , m = waterStartTime.size();
        int land = 1e9 , water = 1e9 , landWater = 1e9 , waterLand = 1e9;
        for(int i = 0 ; i < n ; i++)
            land = min(land , landStartTime[i] + landDuration[i]);
        for(int i = 0 ; i < m ; i++){
            water = min(water , waterStartTime[i] + waterDuration[i]);
            landWater = min(landWater , max(land , waterStartTime[i]) + waterDuration[i]);
        }
        
        for(int i = 0 ; i < n ; i++)
            waterLand = min(waterLand , max(water , landStartTime[i]) + landDuration[i]);
        return min(landWater , waterLand);
    }
};


/*
Any ride can be started after it's min startTime[i] and will go on for duration[i]
Only required to finish two rides(land & water)
First DP came to mind which is overthinking.
Only two possibility
start a land ride , when it finish start the water ride that will finish earliest.
Note: A water ride could start later but have less duration and finish earlier than a previous water ride.
Vice versa.
*/