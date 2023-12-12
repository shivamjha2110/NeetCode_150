class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0,n=nums.size();
	for (auto n : nums) sum += n;
	if ((sum + target) % 2 == 1 || target > sum || target < -sum) return 0;
	int new_target = (sum + target) / 2;
	vector<int> dp(new_target + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = new_target; j >= nums[i]; --j) {
			dp[j] += dp[j - nums[i]];
		}
	}
	return dp[new_target];
    }
};