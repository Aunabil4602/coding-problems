vector<int> par[505];
vector<int> temp_arr;
vector<vector<int> > final_vec;

void back_prop(int pos){
    if(pos==0){
        final_vec.push_back(temp_arr);
        return ;
    }    
    
    for(auto x:par[pos]){
        if(!temp_arr.empty()){
            if(x<temp_arr.back())continue;
        }
        temp_arr.push_back(x);
        back_prop(pos-x);
        temp_arr.pop_back();
    }
    
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i=0;i<=500;i++)par[i].clear();
        temp_arr.clear();
        final_vec.clear();
        
        par[0].push_back(0);
        for(int i=1;i<=500;i++){
            for(auto cur:candidates){
                if(i<cur)continue;
                if(par[i-cur].size()>0){
                    par[i].push_back(cur);
                }
            }
        }
        
        back_prop(target);
        return final_vec;
    }
};
