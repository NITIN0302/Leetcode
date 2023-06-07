//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) 
    {
        int low = 0;
	    int high = 0;
	    int ans = 0;
	    int count =0;
	    while(high<n)
	    {
	        if(arr[high] == 0)
	        {
	            count++;
	        }
	        while(count > m && low<=high)
	        {
	            if(arr[low] == 0)
	            {
	                count--;
	            }
	            low++;
	        }
	        ans = max(ans,high-low+1);
	        high++;
	    }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends