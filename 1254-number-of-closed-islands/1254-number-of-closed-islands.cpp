class Solution {
public:
    int m , n;
    
    void bfs(int i , int j , vector<vector<bool>>& visited , vector<vector<int>>& grid) {
        if(i == -1 || i == m || j == -1 || j == n || grid[i][j] || visited[i][j])
            return;
        
        visited[i][j] = 1;
        grid[i][j] = 1;
        
        bfs(i - 1 , j , visited , grid);
        bfs(i + 1 , j , visited , grid);
        bfs(i , j - 1 , visited , grid);
        bfs(i , j + 1 , visited , grid);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        m = grid.size() , n = grid[0].size();
        vector<vector<bool>> visited(m , vector<bool>(n , 0));
        
        for(int i = 0 ; i < m ; i++) {
            if(grid[i][0] == 0) // left
                bfs(i , 0 , visited ,  grid);
            if(grid[i][n - 1] == 0) // right
                bfs(i , n - 1 , visited , grid);
        }
        
        for(int i = 1 ; i < n - 1 ; i++) {
            if(grid[0][i] == 0) // top
                bfs(0 , i , visited , grid);
            if(grid[m - 1][i] == 0) // bottom
                bfs(m - 1 , i , visited , grid);
        }
        
        int ans = 0;
        
        for(int i = 1 ; i < m - 1 ; i++) {
            for(int j = 1 ; j < n - 1 ; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                    bfs(i , j , visited , grid);
                }
            }
        }

        return ans;
    }
};