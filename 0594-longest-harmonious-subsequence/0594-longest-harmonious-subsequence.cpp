class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i = 0, j = 1;
        while(j<n){
            int diff = nums[j] - nums[i];
            if(diff==1){
                ans = max(ans,j-i+1);
            } 
            if(diff<=1){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};