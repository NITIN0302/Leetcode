//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:

    void solve(int index,int N,vector<int> &note,vector<int> &ans,vector<int> &temp)
    {
        if(N < 0)
        {
            return;
        }
        if(N == 0)
        {
            ans = temp;
            return;
        }
        if(index < 0)
        {
            return;
        }
        if(note[index] <= N)
        {
            temp.push_back(note[index]);
            solve(index,N-note[index],note,ans,temp);
            if(ans.size() != 0)return;
            temp.pop_back();
        }
        else 
        {
            solve(index-1,N,note,ans,temp);
            if(ans.size() != 0)return;
        }
    }

    vector<int> minPartition(int N)
    {
        vector<int> ans,temp;
        vector<int> note = {1,2,5,10,20,50,100,200,500,2000};
        solve(9,N,note,ans,temp);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends