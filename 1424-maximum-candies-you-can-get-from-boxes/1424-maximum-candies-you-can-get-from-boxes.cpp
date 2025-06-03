class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();

        queue<int> q;
        for(int start: initialBoxes){
            q.push(start);
        }
        
        unordered_set<int> closed;
        int ans = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(status[curr]==0){
                closed.insert(curr);
                continue;
            }

            for(int open: keys[curr]){
                status[open]=1;
                if(closed.count(open)){
                    q.push(open);
                    closed.erase(open);
                }
            }

            ans += candies[curr];
            for(int nbr: containedBoxes[curr]){
                q.push(nbr);
            }
        }
        return ans;
    }
};