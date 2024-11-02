class Solution {
public:
    bool isCircularSentence(string s) {
       int n =s.length();
       if(s[0]!=s[n-1])return false;

        for(int i=0;i<n;i++){
            
            while(i+1<n && s[i+1]!=' '){
                i++;
            }
            char first= s[i];
            i++;//skip tht space
            
            char sec=i+1<n?s[i+1]:'1';
            
            if(sec!='1'){
                if(first!=sec)return false;
            }
        } 
        return true;
    }
};