class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements){
        vector <int> line((1e5 + 1), -1);
        for(int i = 0 ; i < elements.size() ; i++){
            int div = elements[i];
            if(line[div] != -1)
                continue;
            for(int j = div ; j < line.size() ; j += div){
                if(line[j] != -1) // assigned by a divisor at smaller index
                    continue;
                line[j] = i;
            }
        }
        for(int i = 0 ; i < groups.size() ; i++)
            groups[i] = line[groups[i]];
        return groups;
    }
};