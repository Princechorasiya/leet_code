class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxBit) {
        int n =nums.size();
        int t= pow(2,maxBit)-1;
        vector<int>xor_arr(n,0);
        vector<int> ans_arr(n,0);
        xor_arr[0]=nums[0];
        ans_arr[0] =t-nums[0];
        for(int i=1;i<n;i++){
            xor_arr[i] =xor_arr[i-1] ^nums[i];
            ans_arr[i] =t-xor_arr[i];


        }
        reverse(ans_arr.begin(),ans_arr.end());
        return ans_arr;

    }
};