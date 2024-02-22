#include <bits/stdc++.h>
using namespace std;


 // checking for github
int tnc(vector<char>&v)
{
    bool flag=false;
    int c=0;
   for(int i=0;i<v.size()-2;i++)
   {
       if(v[i+1]=='@')
       c++;
       else if(v[i+1]=='.')
       continue;
       else if(v[i+1]=='*')
       {
           if(v[i+2]=='@')
           {
            i++;
           c++;
           }
           else if(v[i+2]=='.')
           {
               i++;
           continue;
           }
           else
           {
               flag=true;
           break;
           }
       }
   }
   if(flag!=true)
   {
       if(v[v.size()-1]=='@')
       c++;
   }
   return c;
}

int main() {
    int num;
    cin>>num;
    while(num>0)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<char>v;
        for(char i:s) v.push_back(i);
        int ans=tnc(v);
        cout<<ans<<endl;
        num--;
    }
    return 0;
}