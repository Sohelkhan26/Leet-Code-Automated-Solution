class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1 , high = 1e14 , ans = -1;
        while(low <= high){
            long long time = low + (high - low) / 2 , repairedCar = 0;
            for(int i : ranks)
                repairedCar += (int)sqrt(time / i);
            if(repairedCar >= cars){
                ans = time;
                high = time - 1;
            }else low = time + 1; 
        }
        return ans;
    }
};