
using ll =long long;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ll sum=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            int mini =INT_MAX, maxi =INT_MIN;
            for(int j=i;j<n;j++){
                
                    mini=min(mini,nums[j]);
                    maxi =max(maxi,nums[j]);
                
                // cout <<(maxi-mini)<<endl;
            sum+=(maxi-mini);
            }
        }
        return sum;
    }
};