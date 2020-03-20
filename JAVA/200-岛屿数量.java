class Solution {
    
    void defind(char[][] grid , int x1 , int y1){
        if(grid[x1][y1] == '0') return;
        grid[x1][y1] = '0';
        if(x1>0) defind(grid,x1-1,y1);
        if(y1>0) defind(grid,x1,y1-1);
        if(x1<grid.length-1) defind(grid,x1+1,y1);
        if(y1<grid[0].length-1) defind(grid,x1,y1+1);
     }
    //dfs 因为岛屿上下左右为一块，则在范围内把所有相邻陆地面积置0防止重复计数
    public int numIslands(char[][] grid) {
        int res = 0;
        for(int i = 0;i<grid.length;i++){
            for(int j = 0;j<grid[0].length;j++){
                if(grid[i][j] == '1') 
                {res++;defind(grid,i,j);}
            }
        }
        return res;
    }
}