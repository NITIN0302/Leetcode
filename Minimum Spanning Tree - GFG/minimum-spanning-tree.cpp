//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    
    int find_parent(int n)
    {
        if(parent[n] == n)
        {
            return n;
        }
        parent[n] = find_parent(parent[n]);
    }
    
    void union_find(int a,int b)
    {
        int prt_a = find_parent(a);
        int prt_b = find_parent(b);
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
            parent[prt_a] = prt_b;
            rank[prt_b]++;
        }
    }
};

class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        disjoint_set *ds = new disjoint_set(V);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                pq.push({j[1],{j[0],i}});
            }
        }
        int ans = 0;
        while(!pq.empty())
        {
            int w = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(ds->find_parent(u) != ds->find_parent(v))
            {
                ans += w;
                ds->union_find(u,v);
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