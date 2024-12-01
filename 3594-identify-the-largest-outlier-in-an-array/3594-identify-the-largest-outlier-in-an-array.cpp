class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int sum =accumulate(nums.begin(),nums.end(),0);
        unordered_map<int,int>mp;//stores the value with th count
        for(auto i:nums){
            mp[i]++;
        }
        int maxi=INT_MIN;
         for (int i = 0; i < n; i++) {
        int temp_sum = sum - nums[i]; // Sum after removing nums[i]
        mp[nums[i]]--;               // Temporarily decrement frequency

        if (temp_sum % 2 == 0) {     // Check divisibility by 2
            int to_search = temp_sum / 2;
            if (mp[to_search] > 0) { // Check if partition is possible
                maxi=max(maxi,nums[i]);
            }
        }

        mp[nums[i]]++; // Restore frequency for the next iteration
         }
        return maxi;
    }
};