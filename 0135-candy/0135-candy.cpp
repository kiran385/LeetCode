class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> lge(n,1),rge(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                lge[i] = lge[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rge[i] = rge[i+1] + 1;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(lge[i],rge[i]);
        }
        return ans;
    }
};