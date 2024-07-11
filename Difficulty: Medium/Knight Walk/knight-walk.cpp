//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Directions for knight moves
        vector<pair<int, int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        
        // BFS queue
        queue<pair<int, int>> q;
        q.push({KnightPos[0] - 1, KnightPos[1] - 1});
        
        // Visited array
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        visited[KnightPos[0] - 1][KnightPos[1] - 1] = true;
        
        int steps = 0;
        
        // BFS
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> current = q.front();
                q.pop();
                
                int x = current.first;
                int y = current.second;
                
                // Check if we have reached the target
                if (x == TargetPos[0] - 1 && y == TargetPos[1] - 1) {
                    return steps;
                }
                
                // Explore all possible knight moves
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    // Check if the new position is within bounds and not visited
                    if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newX][newY]) {
                        visited[newX][newY] = true;
                        q.push({newX, newY});
                    }
                }
            }
            ++steps;
        }
        
        return -1; // In case no path is found (though theoretically not possible for a chessboard)
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends