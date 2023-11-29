class Solution {
public:
    void dfs(int i,vector<string> temp,vector<vector<string>> &res,string &s,vector<vector<bool>> &dp){
        if(i==s.length()){
            res.push_back(temp);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(dp[i][j]){
                temp.push_back(s.substr(i,j-i+1));
                dfs(j+1,temp,res,s,dp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0) dp[i][j]=true;
                else if(g==1) dp[i][j]=(s[i]==s[j]);
                else{
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]?true:false);
                }
            }
        }
        vector<vector<string>> res;
        vector<string> temp;
        dfs(0,temp,res,s,dp);
        return res;
    }
};