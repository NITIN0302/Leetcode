//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int majorityElement(int arr[], int size)
    {
        int count = 1;
        int maxi = arr[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i] == maxi)
            {
                count++;
            }
            else
            {
                count--;
                if(count == 0)
                {
                    maxi = arr[i];
                    count++;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<size;i++)
        {
            if(arr[i] == maxi)
            {
                ans++;
            }
        }
        if(ans>size/2)
        {
            return maxi;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends