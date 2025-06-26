class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        long long val = 0;
        int i=0;
        while(i<min(n,32)){
            if(s[n-i-1]=='1'){
                long long power = pow(2,i);
                if(val + power > k){
                    break;
                }
                val += power;
            }
            i++;
        }
        int removeCount = 0;
        while(i<n){
            if(s[n-i-1]=='1'){
                removeCount++;
            }
            i++;
        }
        return n-removeCount;
    }
};