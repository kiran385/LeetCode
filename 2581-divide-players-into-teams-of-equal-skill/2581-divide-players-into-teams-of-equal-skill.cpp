class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        int teamSkill = skill[0] + skill[n-1];
        long long ans = skill[0] * skill[n-1];
        for(int i=1;i<n/2;i++){
            if(skill[i]+skill[n-i-1] != teamSkill){
                return -1;
            }
            else{
                ans += (skill[i]*skill[n-i-1]);
            }
        }
        return ans;
    }
};