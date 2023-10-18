/*

    Time Complexity : O(3^N × 4^M) where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to
    it and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

    Space Complexity : O(3^N × 4^M) where N is the number of digits which have 3 letters( ex: 2,3,4) assigned to
    it and M is the number of digits which has 4 letters(ex: 7,9) assigned to it.

    Solved using String + Backtracking + Hash Table. Recursive Approach.

*/


/***************************************** Approach 1 *****************************************/

class Solution {
private:
    void letterCombinations(string digits, vector<string>& output, string &temp, vector<string>& pad, int index){
        if(index == digits.size()){
            output.push_back(temp);
            return;
        }
        string value = pad[digits[index]-'0'];
        for(int i=0; i<value.size(); i++){
            temp.push_back(value[i]);
            letterCombinations(digits, output, temp, pad, index+1);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        string temp;
        letterCombinations(digits, output, temp, pad, 0);
        return output;
    }
};
