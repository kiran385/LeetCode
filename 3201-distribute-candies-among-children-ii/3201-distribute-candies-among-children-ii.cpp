class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int minChild1 = max(0,n-2*limit);
        int maxChild1 = min(n,limit);
        for(int i=minChild1;i<=maxChild1;i++){
            int N = n-i;
            int minChild2 = max(0,N-limit);
            int maxChild2 = min(N,limit);
            ans += (maxChild2-minChild2+1);
        }
        return ans;
    }
};