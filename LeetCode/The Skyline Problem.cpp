class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n=buildings.size();
        vector<pair<int,pair<int,int> > > dp;
        for(auto x:buildings){
            dp.push_back({x[0],{1,x[2]}});
            dp.push_back({x[1],{0,x[2]}});
        }
        vector<int> ans(2,0);
        vector<vector<int> >ans1;
        sort(dp.begin(),dp.end());
        multiset<int> s;
        s.insert(0);
        for(auto x:dp){
            int w=x.first,h;
            if(x.second.first){
                s.insert(x.second.second);
                h=*(s.rbegin());
            }
            else {
                s.erase(s.find(x.second.second));
                h=*(s.rbegin());
            }
            if(h!=ans[1]){
                ans[0]=(w);
                ans[1]=(h);
                ans1.push_back(ans);
            }
        }
        vector<vector<int> > ans2;
        if(buildings.size()==0)return ans2;
        ans[0]=ans[1]=-1;
        for(auto x:ans1){
            if(ans[0]==x[0]){
                ans[1]=max(ans[1],x[1]);
            }
            else {
                if(ans[0]!=-1){
                    if(ans2.size()==0)ans2.push_back(ans);
                    else if(ans2.back()[1]!=ans[1])ans2.push_back(ans);
                }
                ans=x;
            }
        }            
        ans2.push_back(ans);
        return ans2;
    }
};
