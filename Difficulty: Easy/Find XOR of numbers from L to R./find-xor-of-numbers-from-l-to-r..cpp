//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findx(int r){
        if(r%4==1)return 1;
        if(r%4==2)return r+1;
        if(r%4==3)return 0;
        return r;
    }
    int findXOR(int l, int r) {
        return findx(l-1) ^findx(r);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends