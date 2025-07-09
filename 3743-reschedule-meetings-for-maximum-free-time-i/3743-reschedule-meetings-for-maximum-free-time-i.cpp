class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime(n,0);
        freeTime[0] = startTime[0] - 0;
        for(int i=1;i<n;i++){
            freeTime[i] = startTime[i] - endTime[i-1];
        }
        if(eventTime - endTime[n-1] != 0){
            freeTime.push_back(eventTime - endTime[n-1]);
        }
        vector<int> prefixSum(freeTime.size(),0);
        prefixSum[0] = freeTime[0];
        for(int i=1;i<freeTime.size();i++){
            prefixSum[i] = prefixSum[i-1] + freeTime[i];
        }
        int ans = 0;
        for(int i=0;i<=k && i<prefixSum.size();i++){
            ans = max(ans,prefixSum[i]);
        }
        int j = 0;
        bool check = false;
        for(int i=k+1;i<prefixSum.size();i++,j++){
            check = true;
            ans = max(ans,(prefixSum[i]-prefixSum[j]));
        }
        return check==true ? ans : prefixSum[prefixSum.size()-1];
    }
};