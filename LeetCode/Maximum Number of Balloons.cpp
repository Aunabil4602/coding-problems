#include<bits/stdc++.h>

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> cnt;
        for(auto &c: text){
            cnt[c]++;
        }
        
        int ans=text.length();
        ans=min(ans, cnt['a']);
        ans=min(ans, cnt['b']);
        ans=min(ans, cnt['l']/2);
        ans=min(ans, cnt['o']/2);
        ans=min(ans, cnt['n']);
        
        return ans;
    }
};
