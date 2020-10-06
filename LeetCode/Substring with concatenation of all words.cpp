class Solution { ///////////////////// Using KMP & DP O( s.length * words.length )
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int total_words=words.size();
        if(total_words==0)return vector<int>();
        int n=s.length();
        if(n==0)return vector<int>();
        int dp[words[0].length()+1];
        vector<vector<int> > ck(total_words+1,vector<int>(n+1,0) );
        unordered_map<string,int> str;
        
        for(int i=0;i<words.size();i++){
            string cur=words[i];
            str[cur]++;
            int len=cur.length();
            for(int i=0;i<=len;i++)dp[i]=-1;
            int l=0,r=1;
            while(r<len){
                if(cur[r]==cur[l]){
                    dp[r]=l;
                    l++;r++;
                }
                else {
                    if(l!=0)l=dp[l-1]+1;
                    else r++;
                }
            }
            l=0,r=0;
            while(r<n){
                if(s[r]==cur[l]){
                    l++;
                    r++;
                    if(l==len){
                        ck[i][r-len]=1;
                        l=dp[l-1]+1;
                    }
                }
                else {
                    if(l!=0)l=dp[l-1]+1;
                    else r++;
                }
            }
        }
        int len=words[0].length();
        for(int i=0;i<n;i++){
            if((i-len)<0)continue;
            for(int j=0;j<total_words;j++){
                ck[j][i]+=ck[j][i-len];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if((i+len*(total_words-1))<n){
                int typ=0;
                int last=i+len*(total_words-1);
                for(int j=0;j<total_words;j++){
                    int cnt=ck[j][last];
                    if(i-len>=0)cnt-=ck[j][i-len];
                    if(str[words[j]]==cnt)typ++;
                 }
                
                if(typ==total_words)ans.push_back(i);
            }
        }
        return ans;
    }
};
