class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int north = 0,south = 0,east = 0,west = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                north++;
            }
            else if(s[i]=='S'){
                south++;
            }
            else if(s[i]=='E'){
                east++;
            }
            else if(s[i]=='W'){
                west++;
            }
            int northeast1 = (east+north) - (west+south);
            int northeast2 = west + south;
            int northeast3 = northeast1 + 2*min(k,northeast2);

            int northwest1 = (west+north) - (east+south);
            int northwest2 = east + south;
            int northwest3 = northwest1 + 2*min(k,northwest2);

            int southeast1 = (east+south) - (west+north);
            int southeast2 = west + north;
            int southeast3 = southeast1 + 2*min(k,southeast2);

            int southwest1 = (west+south) - (east+north);
            int southwest2 = east + north;
            int southwest3 = southwest1 + 2*min(k,southwest2);

            int maxDist = max(max(northeast3,northwest3),max(southeast3,southwest3));
            maxDist = max(maxDist,0);
            maxDist = min(maxDist,i+1);

            ans = max(ans,maxDist);
        }
        return ans;
    }
};