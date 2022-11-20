class Solution 
{
public:
    
    void solve(int row,int col,int &ans,int &count,vector<vector<int>>& grid,vector<vector<bool>> &visited)
    {
        int i=0,j=0;
        for(int p=-1;p<=1;p++)
        {
            for(int q=-1;q<=1;q++)
            {
                i = p+row;
                j = q+col;
                if(abs(p) != abs(q) && i>=0 && i<grid.size() && j>=0 && j<grid[0].size()
                && !visited[i][j] && grid[i][j] != 0)
                {
                    count += grid[i][j];
                    visited[i][j] = true;
                    ans = max(ans,count);
                    solve(i,j,ans,count,grid,visited);
                    visited[i][j] = false; 
                    count -= grid[i][j];
                }
            }
        }
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && grid[i][j] != 0)
                {
                    visited[i][j] = true;
                    count += grid[i][j];
                    solve(i,j,ans,count,grid,visited);
                    ans = max(ans,count);
                    count = 0;
                    visited[i][j] = false;
                }
            }
        }
        return ans;
    }
};