// Solution 01
// We can take an element multiple times and add them to get the target value.
// We’re using the help function where the base case is if the index reaches the last of our candidates array & the target became 0 then we’ll push temp to ans vector.
// Now there could be 2 possible cases:
// We’ll include the current element to our temp variable:
// Check the current index value if it’s less than target then we can push it to temp and consider this as a part of our ans vector. Reduce the value from target.
// after that we’ll pop the element from temp, as when it return from this call means that value didn’t give us expected ans.
// We won’t include the current element and move to the next element.
// Time complexity: O(2^k), where k is the sum of target/candidate[i] from i = 0 to size of candidate - 1.

// Code:
//Solution 01:
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        help(0, candidates, target, ans, temp);
        return ans;
    }
    
    void help(int index, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &temp){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
            
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            help(index, candidates, target-candidates[index], ans, temp);
            temp.pop_back();
        }
        help(index+1, candidates, target, ans, temp);
    }
};