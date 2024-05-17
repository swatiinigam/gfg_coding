//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        for(int i=0;i<len;i++)
        {
            cout<<ch[i];
        }
        cout<<endl;
    }
        return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char>s;
    char* str1=new char[len];
    int i=0;
    int top=-1;
    while(i<len){
        s.push(S[i]);
        i++;
    }
    i=0;
    while(!s.empty()){
        
        str1[i]=s.top();
        s.pop();
        i++;
        
    }
    return str1;
}