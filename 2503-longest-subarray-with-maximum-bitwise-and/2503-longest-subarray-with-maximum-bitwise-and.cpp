class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(),nums.end());
        int count = 0,ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxValue){
                count++;
            }
            else{                
                ans = max(ans,count);
                count = 0;
            }
        }
        ans = max(ans,count);
        return ans;
    }
};