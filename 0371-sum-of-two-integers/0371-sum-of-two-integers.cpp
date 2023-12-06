class Solution {
public:
    int getSum(int a, int b) {
        
// Given 14 and 13 (1110 and 1101 respectively)

// first sum = 00011 (3) as: 1110 ^ 1101 = 0011
// next b = 1100 << 1 == 11000 (24) as 1110 & 1101 = 1100

// notice that 3 + 24 is still the sum we want

// next loop:

// sum = 11011 (27)
// b = 000000 << 1 == 0 (as 11000 and 00011 have no overlap)
        
         int sum = a;
        
        while (b != 0)
        {
            sum = a ^ b;//calculate sum of a and b without thinking the carry 
            b = (a & b) << 1;//calculate the carry
            a = sum;//add sum(without carry) and carry
        }
        
        return sum;
    }
};