class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n)
            mask = mask * 2 + 1;
        return mask xor n;
    }
};