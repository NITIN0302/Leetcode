//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
	    queue<pair<int,int>> q;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j] == 1)
	            {
	                visited[i][j] = 1;
	                q.push({i,j});
	            }
	        }
	    }
	    int size = q.size();
	    int level = 0;
	    
	    while(!q.empty())
	    {
	        for(int i=0;i<size;i++)
	        {
	            int toprow = q.front().first;
	            int topcol = q.front().second;
	            q.pop();
	            if(grid[toprow][topcol] == 0)
	               ans[toprow][topcol] = level;
	            int newrow,newcol;
	            for(int p=-1;p<=1;p++)
	            {
	                for(int s=-1;s<=1;s++)
	                {
	                    newrow = toprow + p;
	                    newcol = topcol + s;
	                    if(abs(p)==abs(s) || newrow < 0 || newrow >= grid.size() ||
	                    newcol < 0 || newcol >= grid[0].size())
	                    {
	                        continue;
	                    }
	                    else if(visited[newrow][newcol]==0)
	                    {
	                        q.push({newrow,newcol});
	                        visited[newrow][newcol] = 1;
	                    }
	                    
	                }
	            }
	        }
	        size = q.size();
	        level++;
	    }
	    return ans;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends