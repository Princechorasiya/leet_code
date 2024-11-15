//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &v, int q, vector<int> &indices){
        //write your code here
       vector<int> ans(n, 0);
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] > v[i])
        cnt++;
    }
    ans[i] = cnt;
  }
  vector<int> postans;
  for (int i = 0; i < q; i++)
  {
    postans.push_back(ans[indices[i]]);
  }
  return postans;
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends