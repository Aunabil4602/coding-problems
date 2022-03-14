class Solution {
public:
    string simplifyPath(string path) {
        string str;
        vector<string> obj;
        
        for(int i=0;i<path.length();i++) {
            if(path[i]=='/') {
                if (str.length()>0) {
                    if (str==".."){
                        if(obj.size()>0)obj.pop_back();
                    } 
                    else if (str==".");
                    else obj.push_back(str);
                }
                str="";
            } else {
                str+=path[i];
                
                if(i==(path.length()-1)) {
                    if (str.length()>0) {
                        if (str==".."){
                            if(obj.size()>0)obj.pop_back();
                        } 
                        else if (str==".");
                        else obj.push_back(str);
                    }
                }
            }
        }
        
        
        string ans;
        for(auto s: obj)ans+="/"+s;
        return ans==""?"/":ans;
    }
};
