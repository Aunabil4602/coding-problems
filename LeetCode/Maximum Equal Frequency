#define N 100005
int cnt[N];  // count for frequency of numbers
int check[N];  // count for different frequencies

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt)); 
        memset(check,0,sizeof(check));
        for(auto x:nums)cnt[x]++;
        int n=nums.size();
        int isActive=0;  // total types of frequency
        for(int i=1;i<=n;i++)check[cnt[i]]++;
        for(int i=1;i<=n;i++)if(check[i]>0)isActive++;
        multiset<int> maxx;
        for(int i=1;i<=n;i++)maxx.insert(cnt[i]);

        for(int i=n;i>1;i--){
            if(check[1]==1 && isActive==2){
                return i;
            }
            else if(check[1]>1 && isActive==1){
                return i;
            }
            else {
                int mx=*(maxx.rbegin());
                int temp=isActive;
                if((check[mx]-1)==0)temp--;
                if((check[mx-1]+1)==1)temp++;
                if(temp==1)return i;
            }
            int toDel=nums[i-1];
            check[cnt[toDel]]--;
            if(check[cnt[toDel]]==0)isActive--;

            maxx.erase(maxx.lower_bound(cnt[toDel]));
            cnt[toDel]--;
            maxx.insert(cnt[toDel]);
            check[cnt[toDel]]++;
            if(check[cnt[toDel]]==1)isActive++;

        }
        return 1;
    }
};
