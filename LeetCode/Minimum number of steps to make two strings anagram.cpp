class Solution {
public:
    int minSteps(string s, string t) {
        int ck1[26],ck2[26];
        memset(ck1,0,sizeof(ck1));
        memset(ck2,0,sizeof(ck2));
        for(int i=0;i<s.length();i++){
            ck1[s[i]-'a']++;
            ck2[t[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++)if(ck1[i]>ck2[i])ans+=(ck1[i]-ck2[i]);
        return ans;
    }
};
