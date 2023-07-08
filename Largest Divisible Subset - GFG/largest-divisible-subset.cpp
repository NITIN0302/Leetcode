//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) 
    {
        vector<int> ans;
        vector<int> temp(n,1);
        vector<int> prev(n);
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] % arr[j] == 0)
                {
                    if(temp[i] < temp[j] + 1)
                    {
                        temp[i] = temp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
        }
        
        int maxindex = max_element(temp.begin(),temp.end()) - temp.begin();
        int maxi = temp[maxindex];
        
        
        while(maxi--)
        {
            ans.push_back(arr[maxindex]);
            maxindex = prev[maxindex];
        }
        
        reverse(ans.begin(),ans.end());
        
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
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends