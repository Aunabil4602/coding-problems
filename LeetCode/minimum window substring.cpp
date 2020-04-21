class Solution {   /////////////// Two pointers O(n)
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> dp,cnt;
        int total=0;
        for(int i=0;i<t.length();i++){
            if(cnt[t[i]]==0)total++;
            cnt[t[i]]++;
        }
        int cur=0;
        int n=s.length();
        int j=0;
        int ans=n+10;
        string ss;
        for(int i=0;i<n;i++){
            dp[s[i]]++;
            if(dp[s[i]]==cnt[s[i]])cur++;
            while(cur==total){
                if(ans>(i-j+1)){
                    ans=(i-j+1);
                    ss=s.substr(j,ans);
                }
                if(dp[s[j]]==cnt[s[j]])cur--;
                dp[s[j]]--;
                j++;
            }
        }
        return ss;
    }
};
