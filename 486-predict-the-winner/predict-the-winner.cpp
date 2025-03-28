class Solution {
public:
    int firstPlayer(int i , int j , vector <int> &nums){
        if(i > j)
            return 0;
        if(i == j)
            return nums[i];
        int takeLeft = nums[i] + min(firstPlayer(i + 2 , j , nums), // player 2 took i + 1
                                     firstPlayer(i + 1 , j - 1 , nums) // player 2 took j
        );
        int takeRight = nums[j] + min(firstPlayer(i + 1 , j - 1 , nums), // player 2 took i
                                      firstPlayer(i , j - 2 , nums) // player 2 took j
        );
        return max(takeLeft , takeRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        int first = firstPlayer(0 , nums.size() - 1 , nums);
        return first >= accumulate(nums.begin() , nums.end() , 0ll) - first;
    }
};

/*
FirstPlayer function will calculate the maximum score of player 1 , if both the players play optimally.
It will only calculate the score of first player. So, whatever the second player chooses, first player should take the minimum of them.
*/