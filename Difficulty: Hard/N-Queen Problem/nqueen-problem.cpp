//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     bool isSafe(int row,int col,vector<vector<int>>&board,int n)
    {
        
        int i, j;
        //upright
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i--;j++;
        }
        //right
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            j++;
        }
        //downright
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i++;j++;
        }
        //down
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i++;
        }
        //downleft
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i++;j--;
        }
        //left
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            j--;
        }
        //upleft
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i--;j--;
        }
        //up
        i=row;j=col;
        while(i<n && j<n && i>=0 && j>=0)
        {
            if(board[i][j]==1)return false;
            i--;
        }
        return true;
    }
    void place(int col,int &n,vector<vector<int>>&board,vector<vector<int>>&ans)
    {
        if(col==n)
        {
           
            vector<int>temp;
            for(int i=0;i<board[0].size();i++)
            {
                for(int j=0;j<board.size();j++)
                {
                    if(board[j][i]==1)temp.push_back(j+1);
                    
                }
                
            }
            ans.push_back(temp);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]=1;
                place(col+1,n,board,ans);
                board[row][col]=0;
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>>ans;
        vector<vector<int>>board(n,vector<int>(n,0));
        place(0,n,board,ans);
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

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends