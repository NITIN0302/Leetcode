//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) 
	{
	    if(arr[0] <= arr[n-1])
	    {
	        return 0;
	    }
	    int s = 0,e = n-1;
	    int mid;
	    while(s<e)
	    {
	        mid = (s+(e-s)/2);
	        if(arr[0] <= arr[mid])
	        {
	            s = mid+1;
	        }
	        else
	        {
	            e = mid;
	        }
	    }
	    return s;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends