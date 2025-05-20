class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue <int> pq;
        int n = heights.size();
        for(int i = 0 ; i < n - 1 ; i++){
            int diff = heights[i + 1] - heights[i]; // we can jump to (i + 1)'th building (next building) if there is bricks or ladders or smaller building
            if(diff > 0)
                pq.push(-diff);
            if(pq.size() > ladders){
                bricks += pq.top(); pq.pop();
            }
            if(bricks < 0) // meaning there is not enough bricks to jump the next building (i + 1)'th building. if bricks >= 0 we can jump to next building
                return i;
        }
        return n - 1;
    }
};
/*
Simple logic is to use ladders for the higher diffs. Keep min heap, cause it allows us to fetch the smallest diff in O(1) time. 
*/