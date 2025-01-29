class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxi =0;
        int l=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            //find the max frequecy frim teh map 
            int maxFreq=0;
            for(auto [k,v]:mp){
                maxFreq =max(maxFreq,v);
            }
            int changes =i-l+1 - maxFreq;
            if(changes<=k)maxi=max(maxi,i-l+1);
            else{
                mp[s[l]]--;
                l++;
            }
            

            
        }
        return maxi;
    }
};