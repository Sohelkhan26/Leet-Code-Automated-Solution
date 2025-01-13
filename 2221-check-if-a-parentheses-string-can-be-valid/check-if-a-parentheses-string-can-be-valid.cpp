class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 == 1)
            return false;
        stack <int> lock , unlock;
        for(int i = 0 ; i < s.size(); i++){
            if(locked[i] == '0')
                unlock.push(i);
            else if(s[i] == '(')
                lock.push(i);
            else if(s[i] == ')'){
                if(not lock.empty()){
                    lock.pop();
                    continue;
                }else if(not unlock.empty()){
                    unlock.pop();
                    continue;
                }
                return false;
            }
        }
        while(not lock.empty() and not unlock.empty() and lock.top() < unlock.top())
            lock.pop() , unlock.pop();
        return lock.empty();
    }
};