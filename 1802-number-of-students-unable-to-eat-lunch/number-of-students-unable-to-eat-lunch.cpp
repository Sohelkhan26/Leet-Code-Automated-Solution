class Solution {
public:
    int countStudents(vector<int>& stud , vector<int>& sand) {
        int hungry = stud.size() , count[] = {0 , 0};
        for(int &i : stud)
            count[i]++;
        for(int i : sand){
            if(count[i])
                count[i]-- , hungry--;
            else return hungry;
        }
        return 0;
    }
};

/*
one observation is that order of students don't even matter. If they can't get their desired sandwich they can always go back of the line.
Only case students can't eat is there is no preferred sandwich left for someone. Then they are stuck and others behind that student are also stuck.
*/