class NumberContainers {
public:
    unordered_map <int,set<int>> count; // set contains indices of each number
    unordered_map <int,int> map; // index -> number mapping
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(map.contains(index)){
            int n = map[index];
            count[n].erase(index); // একসময় একদম খালি হয়ে যেতে পারে, সেটা কনসিডার করতে মনে নাই প্রথমে
            if(count[n].empty())
                count.erase(n);
        }
        map[index] = number;
        count[number].insert(index);
    }
    
    int find(int number) {
        if(not count.contains(number))
            return -1;
        return *count[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */