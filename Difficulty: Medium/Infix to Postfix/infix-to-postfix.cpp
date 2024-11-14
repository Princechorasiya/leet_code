//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int priority(char a){
        if(a=='^')return 2;
        if(a=='/'||a=='*')return 1;
        else return 0;
    }
    bool isOperator(char i){
        if(i=='^'|| i=='/'||i=='*'|| i=='+'||i=='-')return true;
        return false;
    }
    string infixToPostfix(string s) {
            string ans;
            stack<char> st;
            //iterrate over the stack 
            for(auto i:s){
                if(i=='('){
                    st.push('(');
                }else if(i==')'){
                    while(!st.empty() &&st.top()!='('){
                        ans+=st.top();
                        st.pop();
                    }
                    st.pop();
                }else if(isOperator(i)){
                    if(st.empty()){
                        st.push(i);
                    }else{
                        if(st.top()=='(')st.push(i);
                        else{
                            while(!st.empty() && st.top()!='(' && priority(st.top()) >= priority(i)){
                                ans+=st.top();
                                st.pop();
                            }
                            st.push(i);
                        }
                    }
                }else{
                    ans+=i;
                }
            }
            
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends