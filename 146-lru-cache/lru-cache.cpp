class LRUCache {
public:
    list <int> dll;
    // most recent key are in front
    unordered_map <int, pair< list<int>:: iterator, int> > seen;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(seen.contains(key)){ // update DLL node and map
            dll.erase(seen[key].first);
            dll.push_front(key);
            seen[key].first = dll.begin();
            return seen[key].second; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(seen.contains(key)){
            dll.erase(seen[key].first); // del DLL node for key
            dll.push_front(key);
            seen[key] = {dll.begin() , value}; // replace old value too
        }else{
            dll.push_front(key);
            seen[key] = {dll.begin() , value};
        }
        if(dll.size() > n){
            seen.erase(seen.find(*dll.rbegin())); // remove key from map too
            dll.pop_back(); // pop the least recent key
        }
    }
};

/*
Design a DS called LRU cache

get() -> return value corresponding to the key
put() -> add value corresponding to the key if not exists. If exists update.

If size exceeds capacity, remove the least recently used key.

DLL(Doubly Linked List) -> store key
most recently used keys will be at the front

map -> store key -> {address of key in DLL , value}

get():
    -if key in map 
        - get address of DLL node from map
        - remove node
        - push front in DLL
        - update address of node in map with key
    - if key not in map 
        - push in front
        - update map with key -> {address , value}
put():
    - if key in map
        - get address of DLL node
        - remove node
        - push front in DLL
        - update address of node in map with key
    - if key not in map
        - push front
        - update map with address -> {address , value}
    - if size > capacity
        - remove from end of DLL
        - remove that key from map too
put() function has extra one feature : removing the least recent key, other things are same right?

*/