//O(n)

#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int st=0;
    while(st<n && s[st]=='a')st++;
    if(st==n)s[n-1]='z';
    while(st<n && s[st]!='a')s[st++]--;
    cout<<s<<endl;
}
