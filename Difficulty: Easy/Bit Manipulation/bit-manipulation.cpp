//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int get(int num,int i){
        int a = num & (int) pow(2,i-1);
        return a>0;
    }
    void set(int num,int i){
        int a =num | (int) pow(2,i-1);
        cout <<a<<" ";
    }
    void cl(int num,int i){
        int t =INT_MAX-(int)pow(2,i-1);
        
        int a= num & t;
        cout <<a;
    }
    void bitManipulation(int num, int i) {
        cout <<get(num,i)<<" ";
        set(num,i);
        cl(num,i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends