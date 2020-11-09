#include<bits/stdc++.h>

using namespace std;

int main(){
    int t,a,b;
    string s;
    vector<int> arr,dp1,dp0;
    cin>>t;
    while(t--){
        cin>>a>>b>>s;
        arr.clear();
        arr.push_back(1);
        for(char c:s){
            if((arr.size()%2)!=(c-'0'))arr[arr.size()-1]++;
            else arr.push_back(1);
        }

        dp0.clear();
        dp0.resize(arr.size(),0);
        dp1.clear();
        dp1.resize(arr.size(),0);
        dp1[0]=b*arr[0]+a;
        for(int i=1;i<arr.size();i++){
            if(i&1){
                dp1[i]=min(dp1[i-1],dp0[i-1]+a);
                dp0[i]=min(dp1[i-1],dp0[i-1]+a);
            }
            else {
                dp0[i]=dp1[i-1];
                dp1[i]=b*arr[i]+dp1[i-1];
            }
        }

        cout<<min(dp0.back(),dp1.back())<<endl;

    }


}
