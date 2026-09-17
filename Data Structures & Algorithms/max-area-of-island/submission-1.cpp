class Solution {
public:
    bool isValid(int i,int j, int n, int m,vector<vector<int>>& grid)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1)
        return true;
        return false;
    }

    void dfs(int i,int j, int n, int m,vector<vector<int>>& grid,int &area,int &cnt)
    {
        grid[i][j]=0;
        cnt++;
        if(isValid(i,j+1,n,m,grid))
        dfs(i,j+1,n,m,grid,area,cnt);

        if(isValid(i+1,j,n,m,grid))
        dfs(i+1,j,n,m,grid,area,cnt);

        if(isValid(i-1,j,n,m,grid))
        dfs(i-1,j,n,m,grid,area,cnt);

        if(isValid(i,j-1,n,m,grid))
        dfs(i,j-1,n,m,grid,area,cnt);

        area=max(area,cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

         int n=grid.size();
        int m=grid[0].size();
        int ans=0,area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cnt=0;
                    dfs(i,j,n,m,grid,area,cnt);
                }
            }
        }
        cout<<area;
        return area;
    }
};
