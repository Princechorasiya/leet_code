class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //find the bti posiition that is set for the xor of the array 
        long arr_xor =0;
        for(auto i:nums){
            arr_xor ^=i;
        }

        int num= (arr_xor &(arr_xor-1)) ^ arr_xor;
        int i=0;
        while((num & (1<<i))==0)i++;
        int ones =0,zeros =0;
        for(auto j :nums){
            if(j &(1<<i))ones^=j;
            else zeros^= j;
        }
        return {ones,zeros};
    }
};

