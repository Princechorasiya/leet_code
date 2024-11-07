class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> v(32,0);
        for(int i=0;i<candidates.size();i++){
            string st =bitset<32>(candidates[i]).to_string();
        
            for(int j=0;j<32;j++){
                if(st[j]=='1')v[j]++;
            }

        }
       
        return *max_element(v.begin(),v.end());
    }
};