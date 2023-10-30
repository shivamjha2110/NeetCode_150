class Solution {
public:
    int maxSubArray(vector<int>& A) {
       int curMax = A[0], preMax = A[0];
        for (int i = 1; i < A.size(); i++){
            preMax = max(preMax+A[i], A[i]);
            curMax = max(curMax, preMax);
        }
        return curMax;
    }
};