class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = INT_MIN;
        unordered_map<int,int> umap;
        int i = 0, temp = 0;
        for(int j=0;j<nums.size();j++){
            umap[nums[j]]++;
            temp += nums[j];
            if(umap[nums[j]]>1){
                while(i<j && umap[nums[j]]>1){
                    umap[nums[i]]--;
                    temp -= nums[i];
                    i++;
                }
            }
            else{
                ans = max(ans,temp);
            }
        }
        return ans;
    }
};