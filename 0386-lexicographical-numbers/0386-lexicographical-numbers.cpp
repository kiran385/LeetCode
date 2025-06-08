class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int num = 1;
        for(int i=0;i<n;i++){
            ans.push_back(num);
            if(num*10 <= n){
                num*=10;
            }
            else{
                if(num+1 <= n && num%10 != 9){
                    num++;
                }
                else{
                    while(((num / 10) % 10) == 9){
                        num = num / 10;
                    }
                    num = num / 10 + 1;
                }
            }
        }
        return ans;
    }
};