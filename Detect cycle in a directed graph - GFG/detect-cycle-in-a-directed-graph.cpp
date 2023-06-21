//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
  
    bool dfs(int src,vector<int> &visited,vector<int> &rec,vector<int> adj[])
    {
        visited[src]= true;
        rec[src] = true;
        
        for(auto i:adj[src])
        {
            if(visited[i] == false)
            {
                bool ans = dfs(i,visited,rec,adj);
                if(ans == true)
                {
                    return true;
                }
            }
            else if(rec[i] == true)
            {
                return true;
            }
        }
        rec[src] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> visited(V,0);
        vector<int> rec(V,0);
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                bool ans = dfs(i,visited,rec,adj);
                if(ans == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends