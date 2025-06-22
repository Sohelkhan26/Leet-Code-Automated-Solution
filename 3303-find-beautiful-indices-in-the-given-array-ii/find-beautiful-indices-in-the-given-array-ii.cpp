class Solution {
public:
    vector<int> robinKarp(const string &s, const string &target) {
        int n = s.size(), m = target.size();
        const int base = 31, mod = 1e9 + 7;

        long long power = 1, hashS = 0, hashT = 0;

        for (int i = 0; i < m; i++) { // hash of string target
            hashT = (hashT * base + (target[i] - 'a' + 1)) % mod;
            power = (power * base) % mod;
        }

        vector<int> ans;
        for (int i = 0 ; i < n; i++) {
            hashS = (hashS * base + (s[i] - 'a' + 1)) % mod;

            if (i >= m) // s[i] * base ^ 0 + s[i] * base ^ 1 + s[i] * base ^ 2... the first index has contribution = base ^ m , m = len(target)
                hashS = (hashS - power * (s[i - m] - 'a' + 1) % mod + mod) % mod;

            if (i + 1 >= m && hashS == hashT) // in case of hash collision, check each string manually.
                ans.push_back(i + 1 - m);  // push starting index
        }

        return ans;
    }

    vector<int> beautifulIndices(string s, string A, string B, int k) {
        vector<int> a = robinKarp(s, A);
        vector<int> b = robinKarp(s, B);
        vector<int> ans;

        int i = 0, j = 0, n = a.size(), m = b.size();

        for (int i = 0, j = 0; i < n; i++) {
            // Shrink window to remove b[j] too far left from a[i]
            while (j < m and b[j] + k < a[i])
                j++;

            // Check if this b[j] is close enough
            if (j < m and abs(a[i] - b[j]) <= k)
                ans.push_back(a[i]);
        }

        return ans;
    }
};
