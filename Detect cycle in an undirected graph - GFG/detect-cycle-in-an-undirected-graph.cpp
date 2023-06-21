//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    
    bool isdfscycle(int src,vector<int> &visited,int parent,vector<int> adj[])
    {
        visited[src] = true;
        
        for(auto i:adj[src])
        {
            if(visited[i] == false)
            {
                bool ans = isdfscycle(i,visited,src,adj);
                if(ans == true)
                {
                    return true;
                }
            }
            else if(i != parent)
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) 
    {
        vector<int> visited(V,0);
        vector<int> parent(V,-1);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == false)
            {
                bool a = isdfscycle(i,visited,-1,adj);
                if(a == true)
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
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends