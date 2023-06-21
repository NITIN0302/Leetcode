//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
  public:
    
    bool isbfscycle(int src,vector<int> &visited,vector<int> &parent,vector<int> adj[])
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            for(auto i:adj[top])
            {
                if(visited[i] == false)
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = top;
                }
                else if(parent[top] != i)
                {
                    return true;
                }
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
                bool a = isbfscycle(i,visited,parent,adj);
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