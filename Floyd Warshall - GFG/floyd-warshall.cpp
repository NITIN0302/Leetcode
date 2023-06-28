//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix)
	{
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            for(int k=0;k<matrix.size();k++)
	            {
	                if(j != k)
	                {
	                    if(matrix[j][i] != -1 && matrix[i][k] != -1)
	                    {
	                        if(matrix[j][k] == -1)
	                        {
	                            matrix[j][k] = matrix[j][i]+matrix[i][k];
	                        }
	                        else
	                        {
	                            matrix[j][k] = min(matrix[j][k], matrix[j][i]+matrix[i][k]);
	                        }
	                    }
	                }
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends