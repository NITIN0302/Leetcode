//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        unordered_map<int,vector<pair<int,int>>> m;
        vector<int> key(V,INT_MAX);
        vector<bool> MST(V,false);
        vector<int> parent(V,-1);
        key[0] = 0;
        parent[0] = -1;
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                m[i].push_back({j[0],j[1]});
                m[j[0]].push_back({i,j[1]});
            }
        }
        
        while(1)
        {
            int minkey = INT_MAX;
            int node = -1;
            for(int i=0;i<V;i++)
            {
                if(MST[i] == false && minkey > key[i])
                {
                    minkey = key[i];
                    node = i;
                }
            }
            if(minkey == INT_MAX || node == -1)
            {
                break;
            }
            MST[node] = true;
            for(auto i:m[node])
            {
                if(MST[i.first] == false && key[i.first] > i.second)
                {
                    key[i.first] = i.second;
                    parent[i.first] = node;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<V;i++)
        {
            ans += key[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends