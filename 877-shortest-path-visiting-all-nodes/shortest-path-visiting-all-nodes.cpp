class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue <pair<int,int>> q; // {node , mask}
        int n = graph.size() , target = (1 << n) - 1 , path = 0;
        set <pair<int,int>> vis;
        for(int i = 0 ; i < n ; i++)
            q.push({i , 1 << i}) , vis.insert({i , 1 << i});
        while(not q.empty()){
            int len = q.size();
            while(len--){
                auto [node , mask] = q.front(); q.pop();
                if(mask == target)
                    return path;
                for(int nei : graph[node]){
                    int newMask = mask | (1 << nei);
                    if(not vis.contains({nei , newMask})){
                        q.push({nei , newMask});
                        vis.insert({nei , newMask});
                    }
                }
            }
            path++;
        }
        return -1;
    }
};

/*
Quite a complex problem to understand at first. Simple BFS দিয়ে হবে না। কারণ প্রথম example এর জন্য একই নোড কয়েকবার ভিসিট করতে হতে পারে। সেক্ষেত্রে আগের কমপ্লিট পাথ বিট্মাস্কের ভেতরে স্টোর করে রাখা হইছে ভিসিটেড এরে হিসেবে যাতে অপ্রয়োজনীয় ভাবে একই নোড কয়েকবার ভিজিট না হয়। 0 -> 1 -> 2 -> 1 এইভাবে চললে ইনিফিনিট লুপ হয়ে যাবে , এটা এভয়েড করতে হবে। 
1. start at each node, do BFS to try reaching all other nodes.
        # 2. Must keep track of visited nodes, else infinite loop may happen.
        # 3. But each node may have to be visited multiple times, as described in the problem
        #    statement. So we cannot be too strict in limiting searches
        # 4. We must describe the state during a search, we need:
        #    - The current node we are on
        #    - Nodes we have visited (Notice the order does not matter in this case, that's a key)

        # each search is described by (currentNode, visited)
        # same search does _not_ have to be repeated, since if re-visited with
        # the same state, it would yield the same result.
        # NOTE this does not prevent revisiting the same node again,
        # it just prevents revisiting it with the same STATE!

        # Since the input size is restricted, we can use a number to encode
        # which nodes have been visited -- the i-th bit is on iff node i has been visited

        # conceptually masks[k] indicates that only node k has been visited
*/