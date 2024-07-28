//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int minSteps(int m, int n, int d)
{
vector<vector<int>>visit(m+1,vector<int>(n+1,0));
    visit[0][0]=1;
    queue<pair<int,int>>q;
    q.push({0,0});
    int step=0;
    while(!q.empty()){
       int sz=q.size();
  for(int i=0;i<sz;i++){
   int x=q.front().first;
   int y=q.front().second;
   q.pop();
   if(y==d || x==d) return step;
   if(x>0 && !visit[0][y]) {
       q.push({0,y});
       visit[0][y]=1;
       }
   if(y>0 && !visit[x][0]){
       q.push({x,0});
       visit[x][0]=1;
       }
   if(x<m && !visit[m][y]){
       q.push({m,y});
       visit[m][y]=1;
       }
       if(y<n && !visit[x][n]){
       q.push({x,n});
       visit[x][n]=1;
       }
       if(m-x>0 && y>0){
       if(x+y<m &&!visit[x+y][0]){
       q.push({x+y,0});
       visit[x+y][0]=1;
       }
       else if(x+y>=m && !visit[m][y-m+x]){
       q.push({m,y-m+x});
       visit[m][y-m+x]=1;
       }
       }
       if(n-y>0 && x>0){
       if(x+y<n &&!visit[0][x+y]){
       q.push({0,x+y});
      visit[0][x+y]=1;
	   }else if(x+y>=n && !visit[x-n+y][n]){
       q.push({x+y-n,n});
       visit[x+y-n][n]=1;
       }
       }
       }
	       step++; 
    }
	    return -1;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends