class Solution {
  public:
    int vowelCount(string& s) {
        unordered_map<char,int>mp;
        string st="aeiou";
        for(auto&ch:s){
            if(st.find(ch)==string::npos)continue;
            mp[ch]++;
        }
        long long val=0;
        if(mp.size()==1)val=1;
        if(mp.size()==2)val=2;
        if(mp.size()==3)val=6;
        if(mp.size()==4)val=24;
        if(mp.size()==5)val=120;
        int a=mp['a'];
        int e=mp['e'];
        int i=mp['i'];
        int o=mp['o'];
        int u=mp['u'];
        
        if(a)val=val*a;
        if(e)val=val*e;
        if(i)val=val*i;
        if(o)val=val*o;
        if(u)val=val*u;
        
        return (int)val;
    }
};