class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map <string,int> freq;
        for(int i = 0 ; i < messages.size() ; i++){
            stringstream ss(messages[i]);
            string s;
            int cnt = 0;
            while(getline(ss , s , ' '))
                cnt++;
            // cout << senders[i] << ' ' << cnt << endl;
            freq[senders[i]] += cnt;
        }
        vector <pair<int,string>> ans;
        for(auto it : freq)
            ans.push_back({it.second , it.first});
        sort(ans.begin() , ans.end() , [&](auto a , auto b){
            if(a.first == b.first)
                return a.second > b.second;
            else return a.first > b.first;
        });
        return ans[0].second;
    }
};