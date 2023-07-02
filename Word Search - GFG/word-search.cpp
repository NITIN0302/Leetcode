//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
public:

    bool solve(int row,int col,vector<vector<char>>& board,vector<vector<int>> &visited,
    string word)
    {
        visited[row][col] = true;
        if(word.length() == 0)
        {
            return true;
        }
        bool ans;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int newrow=row+i,newcol=col+j;
                if(abs(i) == abs(j) || newrow<0 || newcol<0 || newrow>=board.size() 
                || newcol>=board[0].size())
                    continue;
                if(board[newrow][newcol] == word[0] && visited[newrow][newcol] == false)
                {
                    ans = solve(newrow,newcol,board,visited,word.substr(1));
                    if(ans == true)
                    {
                        return true;
                    }
                }
            }
        }
        visited[row][col] = false;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) 
    {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    bool ans = solve(i,j,board,visited,word.substr(1));
                    if(ans == true)return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends