class Solution {
public:
    //bit manipulation way 
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subset =1<<n;
        vector<vector<int>> ans;
        for(int i=0;i<subset;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                //check if the ith bit is set or not 
                if(i & (1<<j)){ 
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};