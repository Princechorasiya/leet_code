//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int l(string a,string b){
        int n =a.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] =dp[i-1][j-1]+1;
                }else{
                    dp[i][j] =max(dp[i-1][j] ,dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
    int longestPalinSubseq(string a) {
        string b=a;
        reverse(b.begin(),b.end());
        return l(a,b);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends