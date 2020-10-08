#include<bits/stdc++.h>

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int  ans=0;
        for(int i=0;i<points.size();i++){
            int mx=0;
            int ver=0,hor=0,same=0;
            map<pair<int,int> ,int> dp;
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                if(points[i]==points[j])same++;
                else if (points[i][0]==points[j][0])ver++;
                else if(points[i][1]==points[j][1])hor++;
                else {
                    int d_x=points[i][0]-points[j][0];
                    int d_y=points[i][1]-points[j][1];
                    int g= __gcd(d_x,d_y);
                    d_x/=g;
                    d_y/=g;
                    dp[{d_x,d_y}]++;
                    mx=max(mx,dp[{d_x,d_y}]);
                }
            }
            dp.clear();
            cout<<mx<<endl;
            ans=max(ans,1+same+max({mx,hor,ver}));
        }
        
        return ans;
    }
};
