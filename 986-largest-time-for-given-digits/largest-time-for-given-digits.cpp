class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector <string> ans;
        sort(arr.begin() , arr.end());
        do{
            int hour = arr[0] * 10 + arr[1];
            int min = arr[2] * 10 + arr[3];
            if(hour < 24 and min < 60){
                string h = (hour < 10 ? "0" : "") + to_string(hour); // for TC 09:01 , 00:00 or something like that
                string m = (min < 10 ? "0" : "") + to_string(min);
                ans.push_back(h + ":" + m);
            }
        }while(next_permutation(arr.begin() , arr.end()));
        sort(ans.rbegin() , ans.rend());
        return ans.empty() ? "" : ans[0];
    }
};

/*
Brute force way. Generate and store all possible combination. Return the largest one by sorting in descending order. ":" won't do any probelm, as it is present in all.
Sort the array first to generate all combination.
*/