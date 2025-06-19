class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int minValue = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-minValue <= k){
                continue;
            }
            else{
                ans++;
                minValue = nums[i];
            }
        }
        return ans;
    }
};