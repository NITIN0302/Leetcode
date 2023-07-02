//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    
    void solve(int index,int a[],int N,string &s,vector<string> &mapping,vector<string> &ans)
    {
        if(index >= N)
        {
            ans.push_back(s);
            return;
        }
        for(int i=0;i<mapping[a[index]].size();i++)
        {
            s.push_back(mapping[a[index]][i]);
            solve(index+1,a,N,s,mapping,ans);
            s.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s;
        solve(0,a,N,s,mapping,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends