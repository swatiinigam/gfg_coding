//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {

public:

	long long int closestPalindrome(long long int num){

	    string s="";

	    long long int n1=0,n2=0,p,q=0;

	    p=num;

	    while(p!=0){

	        s+=(p%10+'0');

	        p/=10;

	        q++;

	    }

	    if(pow(10,q-1)==num && num!=1){

	        return num-1;

	    }

	    reverse(s.begin(),s.end());

	    int size=s.length(),i,j;

	    i=0,j=size-1;

	    while(i<j){

	        s[j--]=s[i++];

	    }

	    for(int i=0;i<size;i++){

	        n1+=(pow(10,i)*(s[i]-'0'));

	    }

	    string w=s;

	    if(size%2==1){

	        if(s[size/2]=='9'){

	            s[size/2]='0';

	            int x=(size/2)-1,y=(size/2)+1;

	            while(x>=0 && y<size){

	                if(s[x]=='9'){

	                    s[x]='0';

	                }

	                if(s[y]=='9'){

	                    s[y]='0';

	                }

	                else{

	                    s[x]++;

	                    s[y]++;

	                    break;

	                }

	                x--;

	                y++;   

	            }

	        }

	        else{

	            s[size/2]++;

	        }

	    }

	    else{

	        if(s[size/2]=='9'){

	            s[size/2]='0';

	            s[(size/2)-1]='0';

	            int x=(size/2)-2,y=(size/2)+1;

	            while(x>=0 && y<size){

	                if(s[x]=='9'){

	                    s[x]='0';

	                }

	                if(s[y]=='9'){

	                    s[y]='0';

	                }

	                else{

	                    s[x]++;

	                    s[y]++;

	                    break;

	                }

	                x--;

	                y++;   

	            }

	        }

	        else{

	            s[size/2]++;

	            s[(size/2)-1]++;

	        }

	    }

	    for(int i=0;i<size;i++){

	        n2+=(pow(10,i)*(s[i]-'0'));

	    }

	    long long int n3=0;

	    if(size%2==1){

	        if(w[size/2]!='0'){

	            w[size/2]--;

	        }

	        else{

	            w[size/2]='9';

	            int x=(size/2)-1,y=(size/2)+1;

	            while(x>=0 && y<size){

	                if(w[x]=='0'){

	                    w[x]='9';

	                }

	                if(w[y]=='0'){

	                    w[y]='9';

	                }

	                else{

	                    w[x]--;

	                    w[y]--;

	                    break;

	                }

	                x--;

	                y++;   

	            }

	        }

	    }

	    else{

	        if(w[size/2]!='0'){

	            w[size/2]--;

	            w[(size/2)-1]--;

	        }

	        else{

	            w[size/2]='9';

	            w[(size/2)-1]='9';

	            int x=(size/2)-2,y=(size/2)+1;

	            while(x>=0 && y<size){

	                if(w[x]=='0'){

	                    w[x]='9';

	                }

	                if(w[y]=='0'){

	                    w[y]='9';

	                }

	                else{

	                    w[x]--;

	                    w[y]--;

	                    break;

	                }

	                x--;

	                y++;   

	            }

	        }

	    }

	    for(int i=0;i<size;i++){

	        n3+=(pow(10,i)*(w[i]-'0'));

	    }

	   // cout << n1 << " " << n2 << " " << n3 << endl;

	    if(abs(num-n1)<abs(num-n2) && abs(num-n1)<abs(num-n3)){

	        return n1;

	    }

	    else if(abs(num-n2)<abs(num-n1) && abs(num-n2)<abs(num-n3)){

	        return n2;

	    }

	    else if(abs(num-n3)<abs(num-n1) && abs(num-n3)<abs(num-n2)){

	        return n3;

	    }

	    else{

	        if(abs(num-n3)==abs(num-n1) && abs(num-n3)==abs(num-n2)){

	            return min(n1,min(n2,n3));

	        }

	        else if(abs(num-n3)==abs(num-n1)){

	            return min(n3,n1);

	        }

	        else if(abs(num-n2)==abs(num-n1)){

	            return min(n2,n1);

	        }

	        else{

	            return min(n2,n3);

	        }

	    }

	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int num;
		cin >> num;
		Solution obj;
		long long int ans = obj.closestPalindrome(num);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends