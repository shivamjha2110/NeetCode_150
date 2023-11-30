class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1,mini=nums[0];
        while(l<=h){
            int mid=l+(h-l)/2;
            mini=min(min(mini,nums[l]),nums[mid]);
            if(nums[mid]>=nums[l]) l=mid+1;
            else h=mid-1;
        }
        return mini;
    }
};