class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while(ans.length() < k){
            int size = ans.length();
            for(int i = 0; i < size; i++){
                char nextChar = 'a' + ((ans[i] - 'a' + 1) % 26);
                ans += nextChar;
            }
        }
        return ans[k - 1];
    }
};