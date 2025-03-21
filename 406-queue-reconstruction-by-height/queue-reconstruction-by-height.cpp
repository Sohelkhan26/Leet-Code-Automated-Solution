class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin() , people.end() , [&](auto a , auto b){
            if(a[0] != b[0])
                return a[0] > b[0];
            return a[1] < b[1];
        });
        for(auto it : people)
            cout << it[0] << ' ' << it[1] << endl;
        for(int i = 0 ;  i < people.size() ; i++)
            ans.insert(ans.begin() + people[i][1] , people[i]); // at each moment there will be people[i][1] people taller to the left/beginning of the queue.
        return ans;
    }
};

/*
We insert people one by one into an empty array. The number k is the position we need to insert. For everyone, we should first insert the higher h person. For the person who has same h we should first insert the person has small k value. For each inserted person, it takes O(n) time to move the person behind him back one position(to the right), so it will take the O(n^2) time for all people.
insert function in vector works by shifting all the elements to the right(->) by one index.
*/