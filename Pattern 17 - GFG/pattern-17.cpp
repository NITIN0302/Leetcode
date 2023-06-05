//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) 
    {
        char a = 'A';
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n-1;j++)
            {
                cout<<" ";
            }
            for(int j=0;j<=i;j++)
            {
                cout<<a;
                a++;
            }
            a--;
            for(int j=0;j<i;j++)
            {
                a--;
                cout<<a;
            }
            a = 'A';
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