//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) 
    {
        char a = 'A';
        char p = a += (n-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cout<<a<<" ";
                a--;
            }
            a = p;
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends