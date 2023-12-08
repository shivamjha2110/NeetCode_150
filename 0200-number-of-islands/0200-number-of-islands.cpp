class Solution {
public:
    
    void check(vector<vector<char>>& grid, int i, int j, int m, int n){
        if (i<0 || j<0 || i==m || j==n || grid[i][j]=='0') return;
        grid[i][j]='0';
        check(grid,i+1,j,m,n);
        check(grid,i,j+1,m,n);
        check(grid,i-1,j,m,n);
        check(grid,i,j-1,m,n);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res=0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    res++;
                    check(grid,i,j,m,n);
                }
            }
        }
        return res;
    }
};