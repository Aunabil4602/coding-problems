class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> dpL(n,0);
        vector<int> dpR(n,0);
        
        map<char,int> cnt;
        for(int i=0;i<n;i++){
            if(cnt[s[i]]==0){
                dpL[i] = 1;
            }
            
            if(i>0)dpL[i]+=dpL[i-1];
            cnt[s[i]]++;
        }
        
        cnt.clear();
        for(int i=n-1;i>=0;i--){
            if(cnt[s[i]]==0){
                dpR[i] = 1;
            }
            
            if(i<n-1)dpR[i]+=dpR[i+1];
            cnt[s[i]]++;
        }
        
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(dpL[i] == dpR[i+1]){
                ans++;
            }
        }
        
        return ans;
    }
};
