class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int charFill = s.size()%k==0 ? 0 : k-(s.size()%k);
        while(charFill--){
            s+=fill;
        }
        for(int i=0;i<s.size();){
            ans.push_back(s.substr(i,k));
            i+=k;
        }
        return ans;
    }
};