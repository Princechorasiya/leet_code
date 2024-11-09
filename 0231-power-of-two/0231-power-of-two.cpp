class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        int t =n& (n-1);
        
        return t==0;
    }
};