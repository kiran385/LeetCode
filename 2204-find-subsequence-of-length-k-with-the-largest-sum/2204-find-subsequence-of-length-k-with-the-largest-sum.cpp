class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size(), i = 0;
        while(k--){
            ans.push_back(nums[i]);
            i++;
        }
        for(int j=i;j<n;j++){
            int minIndex = min_element(ans.begin(),ans.end()) - ans.begin();
            if(ans[minIndex]<nums[j]){
                ans.erase(ans.begin()+minIndex);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};