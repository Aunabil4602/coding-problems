unordered_map<int,int> up,dn;

void mergeUp(int x)
{
    if(!up[x])up[x]=1;
    int cur=x;
    while(up[cur]!=0)cur+=up[cur];
    up[x]=cur-x;
}

void mergeDn(int x)
{
    if(!dn[x])dn[x]=1;
    int cur=x;
    while(dn[cur]!=0)cur-=dn[cur];
    dn[x]=x-cur;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        up.clear();
        dn.clear();
        int ans=0;
        for(auto x:nums){
            mergeUp(x);
            mergeDn(x);
            ans=max(ans,up[x]+dn[x]-1);
        }
        return ans;
    }
};
