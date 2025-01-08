//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   vector<vector<string>> findSequences(string st, string end, vector<string>& wordList) {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        int n=st.length();
        
        if(words.find(end)==words.end())
            return {};
            
        q.push({st});
        
        while(!q.empty())
        {
            int qs=q.size();
            vector<string> found;
            
            while(qs--)
            {
                auto v=q.front();
                st=v.back();
                q.pop();
                
                for(int i=0;i<n;i++)
                {
                    char c=st[i];
                    
                    for(char ch='a';ch<='z';ch++)
                    {
                        if(c==ch)
                            continue;
                            
                        st[i]=ch;
                            
                        if(st==end)
                        {
                            v.push_back(st);
                            ans.push_back(v);
                            
                            v.pop_back();
                        }
                        else if(words.find(st)!=words.end())
                        {
                            found.push_back(st);
                            v.push_back(st);
                            q.push(v);
                            
                            v.pop_back();
                        }
                    }
                    
                    st[i]=c;
                }
                
            }
            
            while(!found.empty())
            {
                words.erase(found.back());
                found.pop_back();
            }
            
            if(ans.size())
                break;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends