#define M 1000000009
#define P 107

long long hhash(string s)
{
    long long ans=0;
    for(int i=0;i<s.length();i++){
        ans*=P;
        ans+=(s[i]);
        ans%=M;
    }
    return ans;
}

int isPal(string s)
{
    int r=s.length()-1;
    int l=0;
    while(l<r){
        if(s[l]!=s[r])return 0;
        l++,r--;
    }
    return 1;
}

string rr(string s)
{
    int r=s.length()-1;
    int l=0;
    while(l<r){
        swap(s[l],s[r]);
        l++;r--;
    }
    return s;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<long long,vector<int> > dp;
        int n=words.size();
        for(int i=0;i<n;i++){
            long long hh=hhash(words[i]);
            dp[hh].push_back(i);
        }
        vector<int> ans(2);
        set<pair<int,int> > ss;
        vector<vector<int> > arr;
        for(int i=0;i<n;i++){
            int len=words[i].length();
            string f="",b="";
            for(int j=0;j<=len;j++){
                f=words[i].substr(0,j);
                b=words[i].substr(j);
                if(isPal(f)){
                    string rev=rr(b);
                    long long hh=hhash(rev);
                    for(auto x: dp[hh]){
                        if(x!=i)ss.insert({x,i});
                    }
                }
                if(isPal(b)){
                    string rev=rr(f);
                    long long hh=hhash(rev);
                    for(auto x:dp[hh]){
                        if(x!=i)ss.insert({i,x});
                    }
                }
                
            }
        }
        for(auto xx:ss){
            ans[0]=xx.first;
            ans[1]=xx.second;
            arr.push_back(ans);
        }
        return arr;
    }
};
