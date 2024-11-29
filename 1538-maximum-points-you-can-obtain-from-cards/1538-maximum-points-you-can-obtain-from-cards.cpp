class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
       int ans=0,sum=0;
       int total =accumulate(cards.begin(),cards.end(),0);
       int n =cards.size();
       int ws =n-k;
       for(int i=0;i<n-k;i++){
        sum+=cards[i];
       }
       ans =max(total-sum,ans);
       for(int i=n-k;i<n;i++){
        sum-=cards[i-ws];
        sum+=cards[i];
        ans =max(total-sum,ans);
       }
       return ans;
    }
};