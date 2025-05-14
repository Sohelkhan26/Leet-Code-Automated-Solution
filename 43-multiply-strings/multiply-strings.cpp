class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")
            return "0";
        int n = num1.size() , m = num2.size();
        vector<int> ans(n + m);
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = m - 1 ; j >= 0 ; j--){
                ans[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); // digit with 10 ^ 0 position , as we are adding numbers, resulting number can be 2 digit number. So, we need to calculate carry before we assign the 1's place digit to the place. Carry is calculated in the next line.
                ans[i + j] += ans[i + j + 1] / 10; // (i + j) position is for carry carry
                ans[i + j + 1] %= 10; // we keep the 1's position digit
            }
        }
        int i = 0;
        string s;
        while(i < ans.size() and ans[i] == 0)
            i++;
        while(i < (n + m))
            s.push_back(ans[i++] + '0');
        return s;
    }
};

/*
num1 = 59
num2 = 98
when we multiply 8 with 5 we are actually multiplying 8 with 50 and adding it to the result. This is how number system works. Now one thing to observe is, 50 = 5 * pow(10 , 1) , this 1 represents the index(from right to left). So, index corresponds to the place value.
i + j + 1 is right to (i + j) So, (i + j + 1) is designated for 1's place digit and (i + j) for carry.
*/