//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfs(int src,vector<bool> &visited,stack<int> &s,unordered_map<int,vector<int>> &m)
	{
	    visited[src] = true;
	    for(auto i:m[src])
	    {
	        if(!visited[i])
	            dfs(i,visited,s,m);
	    }
	    s.push(src);
	}

    void cntcmp(int src,vector<bool> &visited,unordered_map<int,vector<int>> &m)
	{
	    visited[src] = true;
	    for(auto i:m[src])
	    {
	        if(!visited[i])
	            cntcmp(i,visited,m);
	    }
	}
    	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                m[i].push_back(j);
            }
        }
        
        stack<int> s;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,s,m);
            }
        }
        
        m.clear();
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
        }
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                m[j].push_back(i);
            }
        }
        
        int ans = 0;
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            if(!visited[top])
            {
                cntcmp(top,visited,m);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends