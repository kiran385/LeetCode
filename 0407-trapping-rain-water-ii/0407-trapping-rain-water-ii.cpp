class Solution {
    #define pip pair<int,pair<int,int>>

    bool isValid(int& x,int& y,int& m,int& n){
        return (x>=0 && x<m && y>=0 && y<n);
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 or n<3){
            return 0;
        }

        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    minheap.push({heightMap[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }

        int level=0;
        int ans = 0;
        vector<int> dir = {-1,0,1,0,-1};
        
        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();

            int height = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            level = max(level,height);
            
            for(int i=0;i<4;++i){
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                if(isValid(newX,newY,m,n) and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    minheap.push({heightMap[newX][newY],{newX,newY}});
                    if(heightMap[newX][newY] < level){
                        ans += level - heightMap[newX][newY];
                    }                        
                }
            }
        }
        return ans;
    }
};