//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        int count = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        
        int size = q.size(),level = -1;
        while(!q.empty())
        {
            for(int i=0;i<size;i++)
            {
                int toprow = q.front().first;
                int topcol = q.front().second;
                int newrow,newcol;
                q.pop();
                for(int i=-1;i<=1;i++)
                {
                    for(int j=-1;j<=1;j++)
                    {
                        newrow = toprow + i;
                        newcol = topcol + j;
                        if(abs(i) == abs(j) || newrow < 0 || newrow >= grid.size() 
                        || newcol < 0 || newcol >= grid[0].size())
                        {
                            continue;
                        }
                        else if(grid[newrow][newcol] == 1)
                        {
                            q.push({newrow,newcol});
                            grid[newrow][newcol] = 0;
                            count--;
                        }
                    }
                }
            }
            level++;
            size = q.size();
        }
        if(count > 0)
        {
            return -1;
        }
        return level;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends