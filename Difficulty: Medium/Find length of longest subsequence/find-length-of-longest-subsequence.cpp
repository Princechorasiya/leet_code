//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends


int maxSubsequenceSubstring(string x, string y, int n, int m){
    //code
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j =1;j<=n;j++){
            if(x[j-1]==y[i-1]){
                dp[i][j] =1+dp[i-1][j-1];
            }else{
                dp[i][j] =dp[i][j-1];
            }
        }
    }
     int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, dp[i][n]);

    return ans;
    // return dp[m][n];
}