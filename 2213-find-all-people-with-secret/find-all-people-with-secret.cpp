class Solution {
public:
    vector<int>parent;
    int find(int a){
        return parent[a] == a ? a : (parent[a] = find(parent[a]));
    }
    void connect(int a , int b){
        parent[find(a)] = find(b);
    }
    bool connected(int a , int b){
        return find(a) == find(b);
    }
    void reset(int a){
        parent[a] = a;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) { 
        parent.resize(n);
        iota(parent.begin() , parent.end() , 0);
        sort(meet.begin() , meet.end() , [&](auto a , auto b){
            return a[2] < b[2];
        }); // person can propagate secret if next meet time is greater 
        int m = meet.size() , i = 0;
        connect(0 , firstPerson); // both have same parent, any other node that can be connected to this parent can propagate secret
        while(i < m){
            vector <int> secret; // contains group of people with same meeting time
            int time = meet[i][2];
            while(i < m and meet[i][2] == time){
                int a = meet[i][0] , b = meet[i][1];
                connect(a , b);
                secret.push_back(a);
                secret.push_back(b);
                i++;
            }
            for(int node : secret)
                if(not connected(0 , node)) // if this group is connected to source secret they can propagte otherwise they can't , so reset
                    reset(node); // Note : 0 , firstPerson belong to same group
        }
        vector <int> ans;
        for(int i = 0 ; i < n ; i++)
            if(connected(0 , i))
                ans.push_back(i);
        return ans;
    }
};