//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) 
    {
        vector<int> count(32,0);
        for(int i=0;i<n;i++)
        {
            int num = arr[i];
            int j = 0;
            while(num)
            {
                if((num&1) == 1)
                {
                    count[j]++;
                }
                num = num >> 1;
                j++;
            }
        }
        
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            if(count[i]%2 == 1)
            {
                ans = (ans << 1)^1;
            }
            else
            {
                ans = ans<<1;
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    }
    return 0;
}


// } Driver Code Ends