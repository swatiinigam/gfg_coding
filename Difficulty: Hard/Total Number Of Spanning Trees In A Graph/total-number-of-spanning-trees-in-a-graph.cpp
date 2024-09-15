//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSpanningTrees(vector<vector<int>>& graph, int n, int m) {
        // Construct the Laplacian matrix
        vector<vector<int>> laplacian(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u = graph[i][0];
            int v = graph[i][1];

            laplacian[u][u]++;
            laplacian[v][v]++;
            laplacian[u][v]--;
            laplacian[v][u]--;
        }

        // Remove the last row and column
        laplacian.pop_back();
        for (int i = 0; i < n - 1; i++) {
            laplacian[i].pop_back();
        }

        // Calculate the determinant
        return calculateDeterminant(laplacian);
    }

private:
    int calculateDeterminant(vector<vector<int>>& mat) {
        int n = mat.size();

        // Base case: If the matrix is 1x1, return its only element
        if (n == 1) {
            return mat[0][0];
        }

        int det = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<int>> submatrix(n - 1, vector<int>(n - 1, 0));

            // Create the submatrix by excluding the current row and column
            for (int j = 1; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (k != i) {
                        submatrix[j - 1][k < i ? k : k - 1] = mat[j][k];
                    }
                }
            }

            // Calculate the determinant recursively
            det += ((i % 2 == 0) ? 1 : -1) * mat[0][i] * calculateDeterminant(submatrix);
        }

        return det;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin >> n >> m;
	    vector<vector<int>>graph(m, vector<int>(2, 0));
	    for(int i = 0 ; i < m; i++){
	        cin >> graph[i][0] >> graph[i][1];
	    }
	    Solution ob;
	    int ans = ob.countSpanningTrees(graph, n, m);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends