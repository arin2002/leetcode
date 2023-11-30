class Solution {
public:

    int minimumOneBitOperations(int n) 
    {    
        std::array<uint32_t,16> m {0,1,3,2,7,6,4,5,15,14,12,13,8,9,11,10};

        uint32_t out = 0;
        uint32_t mask = 0xF0000000;    
      
        for(int k = 0; k < 8; k++)
        {
            uint32_t i = (n & (mask >> k*4) ) >> (7-k)*4;
            out = out << 4;
            out |= out&0x10 ? (~m[i])&0xF : m[i];
        }

        return out;
    }
};
