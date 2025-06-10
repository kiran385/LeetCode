class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        int oddFreq = 0,evenFreq = 100;
        for(int i:freq){
            if(i!=0 && i%2==0){
                evenFreq = min(evenFreq,i);
            }
            else{
                oddFreq = max(oddFreq,i);
            }
        }
        return oddFreq-evenFreq;
    }
};