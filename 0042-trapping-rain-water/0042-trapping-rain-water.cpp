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
    int trap(vector<int>& height) {
        int n =height.size();
        vector<int> pre(n,-1);
        vector<int> post(n,-1);
        int maxi=-1;

        for(int i=0;i<n;i++){
            int t =height[i];
            pre[i]= maxi;
            maxi= max(t,maxi);
        }
        // print(pre);
        maxi=-1;
         for(int i=n-1;i>=0;i--){
            int t =height[i];
            post[i]= maxi;
            maxi= max(t,maxi);
        }
        // print(post);
        int ans =0;
        for(int i=0;i<n;i++){
           if(pre[i]!=-1 && post[i]!=-1){
            int t =min(pre[i],post[i]) -height[i];
            if(t>0)ans+=t;
           }
        }
        return ans;

    }
};