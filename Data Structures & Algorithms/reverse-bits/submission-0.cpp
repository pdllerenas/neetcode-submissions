class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t res = 0;
       int i = 1;
       while (n) {
        if (n & 1) res |= (1 << (32 - i));
        n >>= 1;
        i++;
       }
       return res;
    }
};
