The Intuition behind the code is to find the maximum sum of a contiguous subarray within the given array nums. It does this by scanning through the array and keeping track of the current sum of the subarray. Whenever the current sum becomes greater than the maximum sum encountered so far, it updates the maximum sum. If the current sum becomes negative, it resets the sum to 0 and starts a new subarray. By the end of the loop, the code returns the maximum sum found.
​
Approach:
We start by initializing two variables: maxSum and currentSum.
maxSum represents the maximum sum encountered so far and is initially set to the minimum possible integer value to ensure that any valid subarray sum will be greater than it.
currentSum represents the current sum of the subarray being considered and is initially set to 0.
We iterate through the nums array using a for loop, starting from the first element and going up to the last element.
For each element in the array, we add it to the current sum currentSum. This calculates the sum of the subarray ending at the current element.
Next, we check if the current sum currentSum is greater than the current maximum sum maxSum.
If it is, we update maxSum with the new value of currentSum. This means we have found a new maximum subarray sum.
If the current sum currentSum becomes negative, it indicates that including the current element in the subarray would reduce the overall sum. In such cases, we reset currentSum to 0. This effectively discards the current subarray and allows us to start a fresh subarray from the next element.
We repeat steps 3 to 5 for each element in the array.
After iterating through the entire array, the variable maxSum will contain the maximum subarray sum encountered.
Finally, we return the value of maxSum as the result, representing the maximum sum of a contiguous subarray within the given array nums.
​
Code
class Solution {
public:
int maxSubArray(vector<int>& nums) {
int maxSum = INT_MIN;
int currentSum = 0;
for (int i = 0; i < nums.size(); i++) {
currentSum += nums[i];
if (currentSum > maxSum) {
maxSum = currentSum;
}
if (currentSum < 0) {
currentSum = 0;
}
}
return maxSum;
}
};