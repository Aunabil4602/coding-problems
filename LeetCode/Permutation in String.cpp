//O(max(n,m))

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt1(26,0),cnt2(26,0);
        for(auto x:s1)cnt1[x-'a']++;
        int n=s1.length();
        int m=s2.length();
        if(m<n)return 0;
        int temp=0;
        for(int i=0;i<n;i++){
            int c=s2[i]-'a';
            cnt2[c]++;
            if(cnt1[c]>=cnt2[c])temp++;
        }
        if(temp==n)return 1;
        for(int i=n;i<m;i++){
            int c=s2[i-n]-'a';
            cnt2[c]--;
            if(cnt1[c]>cnt2[c])temp--;
            
            c=s2[i]-'a';
            cnt2[c]++;
            if(cnt1[c]>=cnt2[c])temp++;
            if(temp==n)return 1;
        }
        return 0;
    }
};
