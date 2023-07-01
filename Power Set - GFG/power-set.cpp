//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int index,string s,string &res,vector<string> &ans)
	{
	    if(index >= s.length())
	    {
	        if(res.length() > 0)
	            ans.push_back(res);
	        return;
	    }
	    
	   // exclude
	   solve(index+1,s,res,ans);
	    
	   // include
	   res.push_back(s[index]);
	   solve(index+1,s,res,ans);
	   res.pop_back();
	}
		vector<string> AllPossibleStrings(string s)
		{
		    vector<string> ans;
		    string res;
		    solve(0,s,res,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends