class Solution {
public:
    int maxDiff(int num) {
        int maxNum = num, minNum = num;
        bool max = false, min = false;
        string number = to_string(num);
        for(int i=0;i<number.size();i++){
            if(!max && number[i]!='9'){
                string temp = number;
                replace(temp.begin(),temp.end(),number[i],'9');
                maxNum = stoi(temp);
                max = true;
            }
            if(!min && number[i]!='1' && number[i]!='0'){
                string temp = number;
                if(i==0){
                    replace(temp.begin(),temp.end(),number[i],'1');
                }
                else{
                    replace(temp.begin(),temp.end(),number[i],'0');
                }
                minNum = stoi(temp);
                min = true;
            }
        }
        return maxNum - minNum;
    }
};