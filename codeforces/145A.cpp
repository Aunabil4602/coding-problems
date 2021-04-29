#include <bits/stdc++.h>
#define LL long long

using namespace std;

string a;
string b;

int main()
{
    cin>>a;
    cin>>b;

    int four=0;
    int seven=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='4' && b[i]=='7'){
            four++;
        }
        else if(a[i]=='7' && b[i]=='4'){
            seven++;
        }
    }

    cout<<max(four,seven)<<endl;
}
