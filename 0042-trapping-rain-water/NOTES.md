Max Left, Max Right So Far!
​
A ith bar can trap the water if and only if there exists a higher bar to the left and a higher bar to the right of ith bar.
To calculate how much amount of water the ith bar can trap, we need to look at the maximum height of the left bar and the maximum height of the right bar, then
The water level can be formed at ith bar is: waterLevel = min(maxLeft[i], maxRight[i])
If waterLevel >= height[i] then ith bar can trap waterLevel - height[i] amount of water.
To achieve in O(1) when looking at the maximum height of the bar on the left side and on the right side of ith bar, we pre-compute it:
Let maxLeft[i] is the maximum height of the bar on the left side of ith bar.
Let maxRight[i] is the maximum height of the bar on the right side of ith bar.
https://assets.leetcode.com/users/images/defee20d-dca9-4244-8817-2f158efecc55_1627750629.6494076.png
​
code :
class Solution { // 4 ms, faster than 89.31%
public:
int trap(vector<int>& height) {
int n = height.size();
vector<int> leftMax(n), rightMax(n);
for (int i = 1; i < n; ++i)
leftMax[i] = max(height[i-1], leftMax[i-1]);
for (int i = n-2; i >= 0; --i)
rightMax[i] = max(height[i+1], rightMax[i+1]);
int ans = 0;
for (int i = 0; i < n; ++i) {
int waterLevel = min(leftMax[i], rightMax[i]);
if (waterLevel >= height[i]) ans += waterLevel - height[i];
}
return ans;
}
};
​
​
​
​
​