/*

    Time Complexity : O(NlogN), Sorting the array(intervals) costs O(NlogN). Where N is the size of
    the Vector(intervals).

    Space Complexity : O(1), Constant Space. Extra space is only allocated for the Vector(output)
    which can go upto size N , however the output does not count towards the space complexity.

    Solved using Array + Sorting.

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }
};