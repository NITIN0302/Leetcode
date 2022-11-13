class Solution {
public:
    
    int solve(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &visited,int &count)
    {
        visited[row][col] = true;
        if(grid[row][col] == 1)
        {
            count++;
        }
        else
        {
            return count;
        }
        for(int i=0;i<grid.size();i++)
        {
            if(!visited[i][col])
            {
                solve(i,col,grid,visited,count);
            }
        }
        for(int i=0;i<grid[0].size();i++)
        {
            if(!visited[row][i])
            {
                solve(row,i,grid,visited,count);
            }
        }
        return count;
    }
    
    int countServers(vector<vector<int>>& grid)
    {
        int ans = 0;
        int count = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    int a = solve(i,j,grid,visited,count);
                    if(a>1)
                    {
                        ans += a;
                    }
                    count = 0;
                }
            }
        }
        return ans;
    }
};