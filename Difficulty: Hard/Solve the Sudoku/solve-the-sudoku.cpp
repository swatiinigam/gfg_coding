//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {

    public:
    
    bool solved(vector<vector<int>> &mat, int r, int c, vector<vector<bool>> &rows, vector<vector<bool>> &cols,vector<vector<vector<bool>>> &box){
        // move to next row
        if(c==9)
            return solved(mat,r+1,0,rows,cols,box);
        // every other row is filled successfully
        if(r==9)
            return true;
        // if vacant cell move forward
        if(mat[r][c]!=0)
            return solved(mat,r,c+1,rows,cols,box);
        
        // put 1-9 possible values
        for(int k=1; k<10; k++){
            // if k in row, col or box, don't put it in cell
            if(rows[r][k] || cols[c][k] || box[r/3][c/3][k] )
                continue;
                
            // set K as present, in current row, col and (3x3) box
            rows[r][k]= true;
            cols[c][k]= true;
            box[r/3][c/3][k]= true;
            // set cell as k
            mat[r][c]=k;
            
            // once solved don't try other numbers... 
            // if backtracks then matrix values will change (passed by reference)
            if(solved(mat,r,c+1,rows,cols,box))
                return true;
            
            // reset k from row, col, box if putting k didn't solve sudoku
            rows[r][k]= false;
            cols[c][k]= false;
            box[r/3][c/3][k]= false;
            
        }
        
        // reset cell if nothing works
        mat[r][c]=0;
        return false;
    }
    
  
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        
        // rows or cols[i][k] checks if k is present in i th row or col
        vector<vector<bool>> rows(9,vector<bool>(10,false));
        vector<vector<bool>> cols(9,vector<bool>(10,false));
        // box[i][j][k]  checks if k is present in i,j box of size 3x3
        vector<vector<vector<bool>>> box(3,vector<vector<bool>>(3,vector<bool>(10,false)));
       
       // initialize above for already present values
       for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){
               int k = mat[i][j];
               if(k){
                   rows[i][k]= true;
                   cols[j][k]= true;
                   box[i/3][j/3][k]= true;
               }
           }
       }
       
        solved(mat,0,0,rows,cols,box);
 
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends