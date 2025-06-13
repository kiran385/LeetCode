class Solution {
public:
    bool isValid(int d,int p,vector<int>& nums){
        int i = 0, count = 0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=d){
                count++;
                i += 2;
            }
            else{
                i += 1;
            }
            if(count==p){
                return true;
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int left = 0, right = 1e9;
        int ans = 1e9;
        while(left<=right){
            int mid = left + (right - left) / 2;
            if(isValid(mid,p,nums)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};