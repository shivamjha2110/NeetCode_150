1st Approach
// I am going to solved this problem by  using String + Backtracking + Hash Table.
/*
​
Time Complexity : O(2^N), Given a string of length N, there are N+1 ways to split it into     two parts. At each
step, we have a choice: to split or not to split. In the worse case, when all choices are     to be checked, that
results in O(2^N).
​
Space Complexity : O(N), The depth of the recursion tree can go upto N.
Solved using String + Backtracking + Hash Table.
​
*/
class Solution {
private:
bool wordBreak(string s, unordered_set<string> &set){
if(s.size() == 0){
return true;
}
for(int i=0; i<s.size(); i++){
if(set.count(s.substr(0, i+1)) && wordBreak(s.substr(i+1), set)){
return true;
}
}
return false;
}
public:
bool wordBreak(string s, vector<string>& wordDict) {
unordered_set<string> set(wordDict.begin(), wordDict.end());
return wordBreak(s, set);
}
};