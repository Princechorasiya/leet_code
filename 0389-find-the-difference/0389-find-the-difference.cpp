class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26,0),v2(26,0);
        for(auto i:s){
            v[i-'a']++;
        }
        for(auto i:t){
            v2[i-'a']++;
        }

        for(int i=0;i<26;i++){
            if(v[i]!=v2[i]){
                return (char) 'a'+i;
            }
        }
        return '-1';
    }
};