class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.length()-1;
        
        while(i<j){
            while(i<s.length() && !isLetter(s[i]))i++;
            while(j>=0 && !isLetter(s[j]))j--;
            
            if(i>=s.length() || j<0 || i>=j)break;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
        return s;
    }
    
    int isLetter(char c){
        if(('a'<=c && c<='z') || ('A'<=c && c<='Z'))return 1;
        return 0;
    }
};
