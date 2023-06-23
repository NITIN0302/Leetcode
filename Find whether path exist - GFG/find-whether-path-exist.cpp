//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j});
                }
            }
        }
        
        int size = q.size();
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
                        else if(grid[newrow][newcol] == 2)
                        {
                            return true;
                        }
                        else if(grid[newrow][newcol] == 3)
                        {
                            q.push({newrow,newcol});
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends