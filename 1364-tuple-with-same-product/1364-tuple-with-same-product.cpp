class Solution {
public:
    int getc(int n){
        if(n==1)return 0;
        return (n*(n-1))/2;
    }
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n =nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mul =nums[i]*nums[j];
                mp[mul]++;
            }
        }
        int pairs =0;
        for(auto [k,v]:mp){
            
            pairs+=(getc(v)*8);
        }
        return pairs;
    }
};