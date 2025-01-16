class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n%2==0 && m%2==0){
            return 0;
        }else if(n%2==1&&m%2==0){
            int xorr=0;
            for(auto i:nums2)xorr^=i;
            return xorr;
        }else if(n%2==0 && m%2==1){
            int xorr=0;
            for(auto i:nums1)xorr^=i;
            return xorr;
        }else{
            int xorr=0;
            for(auto i:nums1)xorr^=i;
            for(auto i:nums2)xorr^=i;
            return xorr;
        }
        return -1;
    }
};