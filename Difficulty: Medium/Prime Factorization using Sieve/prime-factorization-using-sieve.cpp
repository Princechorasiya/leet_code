//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h> 
using ll=long long;
using llt=long long int;
using namespace std; 
template <typename T> void print(const T &container) { for (const auto &element : container) cout << element << " "; cout << endl; } 
template <typename T> void print(const vector<vector<T>> &container) { for (const auto &row : container) { for (const auto &element : row) cout << element << " "; cout << endl; } } 
template <typename T, size_t rows, size_t cols> void print(T (&arr)[rows][cols]) { for (size_t i = 0; i < rows; i++) { for (size_t j = 0; j < cols; j++) cout << arr[i][j] << " "; cout << endl; } } 
template <typename T> void print(T *arr, int size) { for (int i = 0; i < size; i++) cout << arr[i] << " "; cout << endl; } 
template <typename T> void print(T *arr, int start, int end) { for (int i = start; i <= end; i++) cout << arr[i] << " "; cout << endl; } 
template <typename T> void print(const vector<T> &v, int start, int end) { for (int i = start; i <= end; i++) cout << v[i] << " "; cout << endl; } 
template <typename T1, typename T2> void print(const pair<T1, T2> &p) { cout << "first: " << p.first << " second: " << p.second << endl; } 
template <typename T1, typename T2> void print(const vector<pair<T1, T2>> &v) { for (const auto &p : v) print(p); } 
template <typename K, typename V> void print(const unordered_map<K, V> &umap) { for (const auto &pair : umap) cout << pair.first << ": " << pair.second << endl; } 
template <typename K, typename V> void print(const map<K, V> &mp) { for (const auto &pair : mp) cout << pair.first << ": " << pair.second << endl; } 
template <typename T> void print(const set<T> &s) { for (const auto &element : s) cout << element << " "; cout << endl; } 
template <typename T> void print(const unordered_set<T> &us) { for (const auto &element : us) cout << element << " "; cout << endl; }

class Solution {
  public:
     void sieve(){}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        //sieve 
        vector<int> p(n+1,1);
        p[0]=0,p[1]=1;
        for(int i=2;i<=n;i++){
            if(p[i]==1){
                p[i]= i;
                if((ll)i*i<=n)
                for(ll j=i*i;j<=n;j+=i){
                    if(p[j]==1){
                        p[j]=i;
                    }
                }
            }
        }
        // print(p);
       vector<int> ans;
       while(n>1){
           int t =p[n];
           ans.push_back(t);
           n/=t;
       }
       return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends