class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int minEle = nums[0];
        for(int i=1;i<nums.size();i++){
            minEle = min(minEle,nums[i]);
            if(nums[i]>minEle){
                ans = max(ans,nums[i]-minEle);
            }
        }
        return ans;
    }
};