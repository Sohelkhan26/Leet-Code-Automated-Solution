class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map <string,int> count;
        for(string s : cpdomains){
            stringstream ss(s);
            string ans , domain;
            getline(ss , ans , ' ');
            getline(ss , domain);
            while(not domain.empty()){
                count[domain] += stoi(ans);
                int pos = domain.find('.');
                if(pos == -1)
                    break;
                domain = domain.substr(pos + 1);
            }
        }
        vector <string> result;
        for(auto it : count)
            result.push_back(to_string(it.second) + " " + it.first);
        return result;
    }
};