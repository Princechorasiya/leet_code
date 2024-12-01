class Solution {
public:
    int smallestNumber(int n) {
        int k =log2(n);
        return pow(2,k+1)-1;
    }
};