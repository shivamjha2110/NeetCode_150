let's understand this...if n=1101 and res=0000
let's make a loop for i=0->4
when i=0, res will make left shift but it will remain 0000 and when i=0 there is no change is n and when we do bitwise & with 1 it will give 1, so after i=0 res=0001
when i=1
res=0010 and n will be 1101>>1 & 1 now this will give 0 since i is 1 and n will be 0110 after bit opr and res=0010
when i=2
res=0100 and n will be 1101>>2 & 1 now this will give 1 since ith pos is 2 and n will be 0011 and res=0101
when i=2
res=1010 and n will be 1101>>3 & 1 now this will give 1 since ith pos is 3 and n will be 0001 and res=1011
finally res will be 1101. One thing to note here we are not making any changes in n when we do (n<<i) we are just shifting i times but no change to n. We can make this more faster if we make permanent change in n and take only last bit.