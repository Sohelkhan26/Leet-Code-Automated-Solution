class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<long long> ans;
        int base = 109, mod = 1e9 + 9, n = text.size();
        vector<long long> prefix(n + 1), power(n + 1, 1);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] * base + (text[i] - 'a' + 1)) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }

        auto hash = [&](int left, int right) -> long long {
            return (prefix[right] - (prefix[left] * power[right - left]) % mod + mod) % mod;
        };

        for (int len = 1; len <= n / 2; len++) {
            int count = 0;
            for (int left = 0, right = len; left + len < n; left++, right++) {
                count = (text[left] == text[right] ? count + 1 : 0);
                if (count == len) {
                    ans.insert(hash(left, left + len));
                    count--;
                }
            }
        }

        return ans.size();
    }
};
