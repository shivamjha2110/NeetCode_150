class Solution {
public:
    int minimumOneBitOperations(int n) {
        int i=1;
        vector<int> index;
        while(n){
            if(n&1){
               index.push_back(i);
            }
            i++;
            n>>=1;
        }
        int h=index.size();
        i=0;
        long long ans=0;
        if(index.size()==1)return pow(2,index[0])-1;
        for(int j=h-1;j>=0;j--){
           if(i){
             ans-=(pow(2,index[j])-1);
             i--;
           }
           else{
               ans+=(pow(2,index[j])-1);
               i++;
           }
        }
        return ans;
    }
};