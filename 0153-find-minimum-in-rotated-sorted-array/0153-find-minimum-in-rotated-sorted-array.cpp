class Solution {
public:
    int findMin(vector<int>& nums) {
        int x = nums[0];
        for (int i = 1; i <=nums.size(); i++) {
        if (nums[i-1] < x) x = nums[i-1];
    }
        return x;
    }
};