//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> times;
        for(int i=0;i<n;i++)
        {
            times.push_back({start[i],end[i]});
        }
        int count = 0;
        sort(times.begin(),times.end(),cmp);
        int ans = 0;
        int maxi = 0;
        for(int i=0;i<times.size();i++)
        {
            if(maxi < times[i].first)
            {
                ans++;
                maxi = times[i].second;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends