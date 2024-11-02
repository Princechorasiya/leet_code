class Solution {
public:
    string makeFancyString(string s) {
        ///take a counter if smae character as prev increase if not make it zero 

        int cnt =1;
        
        int n =s.length();
        string ans ;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                cnt =min(cnt,2);
                
                    for(int j=0;j<cnt;j++)ans+=s[i-1];
                
                cnt =1;


            }
        }
        cnt =min(cnt,2);
                
                    for(int j=0;j<cnt;j++)ans+=s[n-1];
                

        return ans;
    }
};