class Solution {
public:
    int count = 0;
    void subsets(vector<int>& nums, int index, int curr, int maxOR){
        if(curr==maxOR){
            count++;
        }
        for(int j=index;j<nums.size();j++){
            subsets(nums, j+1, curr | nums[j], maxOR);
        }
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int i=0;i<nums.size();i++){
            maxOR = maxOR | nums[i];
        }
        subsets(nums, 0, 0, maxOR);
        return count;
    }
};