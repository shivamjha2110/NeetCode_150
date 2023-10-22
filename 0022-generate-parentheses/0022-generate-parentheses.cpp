class Solution {
public:
         vector<string>result;
    
    void function(int open,int close,int n,string current)
    {
        if(current.length()==n*2)
        {
            result.push_back(current);
            return;
        }
        if(open<n)  function(open+1,close,n,current+"(");
        if(close<open)  function(open,close+1,n,current+")");
    }
    vector<string> generateParenthesis(int n) {
        function(0,0,n,"");
        return result;
    }
};