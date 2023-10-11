class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //(Two-pass Hash table)
        unordered_map<int,int>numMap;
        int n=nums.size();
        // Build the hash table
        for(int i=0;i<n;i++){
            numMap[nums[i]]=i;
        }
        //find complement
        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            if(numMap.count(complement) && numMap[complement]!=i){
                return{i,numMap[complement]};
            }
        }
        return {}; //No solution found
    }
};