class Solution {
public:
    
    bool solve(int index,int i,int j,int row,int col,vector<vector<char>>& board,vector<vector<bool>>                  &visited,string word)
    {
        
        if(index >= word.length())
        {
            return true;
        }
        
        for(int p=-1;p<=1;p++)
        {
            for(int q=-1;q<=1;q++)
            {
                int r = i+p;
                int s = j+q;
                if(abs(p) != abs(q) && r >= 0 && s >= 0 && r < row && s < col && 
                   board[r][s] == word[index] && !visited[r][s])
                {
                    visited[r][s] = true;
                    bool a = solve(index+1,r,s,row,col,board,visited,word);
                    if(a == true)
                    {
                        return true;
                    }
                    visited[r][s] = false;
                }
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(word[0] == board[i][j])
                {
                    visited[i][j] = true;
                    if(solve(1,i,j,row,col,board,visited,word))
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};