class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int top = 0, left = 0, 
            bottom = grid.size() - 1, right = grid[0].size() - 1;

        while(top < bottom && left < right){
            int length = bottom - top, width = right - left,
                perimeter = 2 * length + 2 * width,
                rotations = k % perimeter;
            
            while(rotations--){
                int temp = grid[top][left];

                for(int i = left; i < right; i++){
                    grid[top][i] = grid[top][i+1];
                }
                for(int i = top; i < bottom; i++){
                    grid[i][right] = grid[i+1][right];
                }
                for(int i = right; i > left; i--){
                    grid[bottom][i] = grid[bottom][i-1];
                }
                for(int i = bottom; i > top; i--){
                    grid[i][left] = grid[i-1][left];
                }

                grid[top+1][left] = temp;
            }
            top++; left++; bottom--; right--;
        }
        return grid;
    }
};