//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    class disjoint_set
    {
       public:
       vector<int> parent,rank;
       
       disjoint_set(int n)
       {
           parent.resize(n);
           rank.resize(n);
           for(int i=0;i<n;i++)
           {
               parent[i] = i;
               rank[i] = 1;
           }
       }
       
       int find_parent(int i)
       {
           if(parent[i] == i)
           {
               return i;
           }
           return parent[i] = find_parent(parent[i]);
       }
       
       void union_find(int a,int b)
       {
           int prt_a = find_parent(a);
           int prt_b = find_parent(b);
           
           if(prt_a == prt_b)return;
           
           if(rank[prt_a] > rank[prt_b])
           {
               parent[prt_b] = prt_a;
           }
           else if(rank[prt_b] > rank[prt_a])
           {
               parent[prt_a] = prt_b;
           }
           else
           {
               parent[prt_b] = prt_a;
               rank[prt_a]++;
           }
       }
    };
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        disjoint_set ds(n*m + 1);
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<int> res;
        int ans = 0;
        
        vector<vector<int>> traverse = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0;i<operators.size();i++)
        {
            int newrow,newcol;
            int row = operators[i][0];
            int col = operators[i][1];
            if(grid[row][col] == 1)
            {
                res.push_back(ans);
                continue;
            }
            grid[row][col] = 1;
            ans++;
            for(int i=0;i<4;i++)
            {
                newrow = row + traverse[i][0];
                newcol = col + traverse[i][1];
                if(newrow < 0 || newrow >= n || newcol < 0 || newcol >= m)
                {
                    continue;
                }
                if(grid[newrow][newcol] == 1 && 
                ds.find_parent(row*m + col) != ds.find_parent(newrow*m + newcol))
                {
                    ans--;
                    ds.union_find(row*m + col,newrow*m + newcol);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends