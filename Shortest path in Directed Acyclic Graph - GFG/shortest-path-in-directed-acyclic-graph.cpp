//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void toposort(int src,unordered_map<int,vector<pair<int,int>>> &m,
    stack<int> &s)
    {
        for(auto i:m[src])
        {
            toposort(i.first,m,s);
        }
        s.push(src);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        vector<int> ans(N,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> m;
        stack<int> s;
        for(int i=0;i<edges.size();i++)
        {
            m[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        toposort(0,m,s);
        
        ans[0] = 0;
        int isvalid = 0;
        
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            for(auto i:m[top])
            {
                ans[i.first] = min(ans[i.first],ans[top] + i.second);
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(ans[i] == INT_MAX)
            {
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends