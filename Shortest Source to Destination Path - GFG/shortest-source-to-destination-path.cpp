//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> grid, int X, int Y) 
    {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> q;
        if(grid[0][0] == 0 || grid[X][Y] == 0)
        {
            return -1;
        }
        if(X == 0 && Y == 0)
        {
            return 0;
        }
        q.push({0,0});
        visited[0][0] = true;
        int level = 0;
        int size = q.size();
        while(!q.empty())
        {
            level++;
            for(int i=0;i<size;i++)
            {
                int toprow = q.front().first;
                int topcol = q.front().second;
                int newrow,newcol;
                q.pop();
                for(int r=-1;r<=1;r++)
                {
                    for(int s=-1;s<=1;s++)
                    {
                        newrow = toprow + r;
                        newcol = topcol + s;
                        if(abs(r) == abs(s) || newrow < 0 || newrow >= grid.size() 
                        || newcol < 0 || newcol >= grid[0].size())
                        {
                            continue;
                        }
                        else if(newrow == X && newcol == Y)
                        {
                            return level;
                        }
                        else if(grid[newrow][newcol] == 1 && visited[newrow][newcol] == false)
                        {
                            q.push({newrow,newcol});
                            visited[newrow][newcol] = 1;
                        }
                    }
                }
            }
            size = q.size();
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends