class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        pair<string,int> arr[n];
        for(int i=0;i<n;i++){
            arr[i].first=strs[i];
            arr[i].second=i;
        }
        for (int i=0;i<n;i++)sort(arr[i].first.begin(),arr[i].first.end());

        sort(arr,arr+n);
        string pre;
        vector<string> ans;
        vector<vector<string> > ans1;
        for(int i=0;i<n;i++){
            string cur=arr[i].first;
            if(cur!=pre){
                if(ans.size()>0)ans1.push_back(ans);
                ans.clear();
            }
            ans.push_back(strs[arr[i].second]);
            pre=cur;
        }
        if(ans.size()>0)ans1.push_back(ans);
        return ans1;
    }
};
