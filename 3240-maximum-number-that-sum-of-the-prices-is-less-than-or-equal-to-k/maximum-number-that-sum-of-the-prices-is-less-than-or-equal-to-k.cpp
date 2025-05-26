class Solution {
public:
    typedef long long ll;

    long long findMaximumNumber(ll k, int x) {
        ll low = 1, high = 1e15, ans = -1;

        auto sumOfSetBits = [&](ll n) {
            ll sum = 0;
            for (int i = 0; i < 63; i++) {
                if ((i + 1) % x == 0) { // bit positions x, 2x, 3x...
                    ll blockSize = (1LL << (i + 1));     // 2^(i+1)
                    ll setBitCountPerBlock = (1LL << i); // 2^i
                    ll fullBlocks = (n + 1) / blockSize;
                    ll rem = (n + 1) % blockSize;
                    sum += fullBlocks * setBitCountPerBlock;
                    sum += max(0LL, rem - setBitCountPerBlock);
                }
            }
            return sum;
        };

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (sumOfSetBits(mid) <= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
