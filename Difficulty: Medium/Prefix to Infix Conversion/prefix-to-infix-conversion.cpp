//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOperator(char a){
        if(a=='^'|| a=='/'||a=='*'||a=='+'||a=='-')return true;
        return false;
    }
    string preToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(int i=exp.size();i>=0;i--){
            if(isOperator(exp[i])){
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string t="("+a+exp[i]+b+")";
                st.push(t);
                
            }else{
                st.push(string(1,exp[i]));
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends