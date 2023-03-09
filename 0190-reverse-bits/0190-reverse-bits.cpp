class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int count = 32;
        while(n) {
            ans <<= 1;
            if (n & 1)
                ans |= 1;
            n >>= 1;
            count--;
        }
        while(count){
            count--;
            ans <<= 1;}
        return ans;
    }
};