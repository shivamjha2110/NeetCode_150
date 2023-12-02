class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> m,p;
        int result=0;
        
          for(auto c:chars)
               m[c]++;
           
          for(int i=0;i<words.size();i++)
          {   
              p=m;
              bool ok=1;
             
              for(int j=0;j<words[i].size();j++)
              {
                 p[words[i][j]]--; 
                 if(p[words[i][j]]<0)
                 {
                     ok=0;
                     break;
                 }
              }
              if(ok)
                  result+=words[i].size();
          }
        return result;
    }
};