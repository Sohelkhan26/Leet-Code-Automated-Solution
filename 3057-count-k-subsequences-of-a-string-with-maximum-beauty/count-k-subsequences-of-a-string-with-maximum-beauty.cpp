class Solution {
public:
    int mod = 1e9 + 7;
    int power(int n , int p){
        if(p == 0)
            return 1;
        long long ans = power(n , p / 2);
        ans = (ans * ans) % mod;
        if(p % 2) ans = (ans * n) % mod;
        return ans;
    }
    vector <int> factorial;
    int nCr(int n , int r){
        cout << n << endl;
        int numerator = factorial[n];

        int denominator = (1ll * factorial[n - r] * factorial[r]) % mod;
        return (1ll * numerator * power(denominator , mod - 2)) % mod; // FLT
    }
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n = s.size() + 1;
        factorial.resize(n , 1);
        for(int i = 2 ; i < n ; i++)
            factorial[i] = (1ll * factorial[i - 1] * i) % mod;
        priority_queue <int> pq;
        unordered_map <char,int> freq;
        for(const char &c : s)
            freq[c]++;
        for(const auto &[c , cnt] : freq)
            pq.push(cnt);
        if(pq.size() < k)
            return 0;
        long long ans = 1;
        while(k and not pq.empty()){
            int equalCount = 0 , f = pq.top(); 
            while(not pq.empty() and pq.top() == f)
                equalCount++ , pq.pop();
            if(equalCount <= k){
                ans = (ans * power(f , equalCount)) % mod;
                k -= equalCount;
            } else{
                ans = (ans * power(f , k)) % mod; // one slot can have 1 out of 'f' character. Note that each char in subseq is unique 
                ans = (ans * nCr(equalCount , k)) % mod; // equal count choice and k slots.
                break;
            }
        }
        return (int)ans;
    }
};

/*
Given a string and k
find all k length subsequence with unique characters.
beauty of a subseq is sum frequency of each character in the original string.
return the count-of-subseq which have max beauty(out of all subseq).
is the problem trying to throw me off?
k could be at most 26 , if k > 26 there could be only one subseq with max beauty
that is including each char and beauty = s.size()
k = 1 ans = count(max-freq-char)

have to try each char in subseq?
to make a subseq with max beauty, we should only include characters with max freq in s, right?
But why does it exceed capacity of int?
suppose freq(a) -> 100 in s
we can select any a for one slot in k len subseq
So, ans *= 100
One small edge case:
suppose freq(a) -> 100 , freq(b) -> 100 , k = 1 or slot
we have 1 slot and 200 characters to choose from
if n elements have equal frequency, there is nCr(n , k) way to choose a character for the k slots.
And for each slots, there is frequency of that character choice.
All of this should be multiplied and thus the count exceeds int.

*/