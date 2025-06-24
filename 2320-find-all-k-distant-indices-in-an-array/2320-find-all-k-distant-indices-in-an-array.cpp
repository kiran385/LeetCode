class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        set<int> s;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int j = max(0,i-k);
                int x = min(i+k+1,n);
                while(j<x){
                    s.insert(j++);
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};