class Solution {
public:
    int countPrimes(int n) {
        //return the number which are less than n 

        //brute for all number if they are prime or not 

        //sieve of erathanus'
        if(n<=1)return 0;
        int ans =0;
        vector<int>p(n,1);
        p[0] =0;
        p[1] =0;
        for(int i=0;i<n;i++){
            if(p[i] ==1){
                ans++;
                for(int j =i;j<n;j+=i){
                    
                    if(j<n+1)p[j] =0;
                }
            }
        }
        return ans;
    }
};