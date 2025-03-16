class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk = 0 , Max = -1;
        for(int i = 0 ; i < arr.size() ; i++){
            Max = max(Max , arr[i]);
            if(Max == i)
                chunk++;
        }
        return chunk;
    }
};
/*
Elements are in the range [0 , n - 1].
Element i can be put on it's original place if there are at least i elements so far. We will try to maximize the number of chunks. So we have to minimize the length of each chunk.
So as soon as we can accomodate a elements in it's original place, we call it a chunk.
Max keeps track of minimum elements required to sort the chunk.
*/