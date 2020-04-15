#define LL long long
#define N 100005
int dp[N];

void update(int x,int val)
{
    x++;
    while(x<N){
        dp[x]+=val;
        x+=(x&-x);
    }
}

int query(int x)
{
    x++;
    int sum=0;
    while(x>0){
        sum+=dp[x];
        x-=(x&-x);
    }
    return sum;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        memset(dp,0,sizeof (dp));
        set<LL> temp;
        for(auto x:nums){
            temp.insert((LL)x);
            temp.insert((2LL)*x);
        }
        map<LL,int> pos;
        int id=0;
        for(auto x:temp){
            pos[x]=id++;
        }
        reverse(nums.begin(),nums.end());
        int ans=0;
        for(auto x:nums){
            ans+=query(pos[x]);
            update(pos[((LL)x)*2]+1,1);
        }
        return ans;
    }
};
