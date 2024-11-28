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
    vector<int> getPrev(vector<int> &nums){
    // find out the no of times that element that can occur
    int n = nums.size();

    vector<int> prevSmallest(n, -1);
    
    // find the prev smallest
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
      if (st.empty())
      {
        st.push(i);
      }
      else
      {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
          st.pop();
        }
        if (!st.empty())
          prevSmallest[i] = st.top();
        st.push(i);
      }
    }
    return prevSmallest;
}
vector<int> getNext(vector<int> &nums){
    stack<int> st2;
    int n =nums.size();
    vector<int>nextSmallest(n,n);
    // get the nextSmallest indexes
    for (int i = n - 1; i >= 0; i--)
    {
      if (st2.empty())
      {
        st2.push(i);
      }
      else
      {
        while (!st2.empty() && nums[st2.top()] >= nums[i])
          st2.pop();
        if (!st2.empty())
        {
          nextSmallest[i] = st2.top();
        }
        st2.push(i);
      }
    }
    return nextSmallest;
}
    int largestRectangleArea(vector<int>& heights) {
        //for  each element find the next smallest element on the left and right 
        vector<int> prev =getPrev(heights);
        vector<int> next =getNext(heights);
        int maxi =0;
        int n =heights.size();
        for(int i=0;i<n;i++){
            int leftW =prev[i]+1;
            int rightW =next[i]-1;
            int area =heights[i] *(rightW-leftW+1);
            // cout <<area<<endl;
            maxi =max(maxi,area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m =matrix[0].size();
        vector<int> his(m,0);
        int maxi =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')his[j]=0;
                else his[j]=his[j]+1;
            }
            // print(his);
            maxi =max(largestRectangleArea(his),maxi);
        }
        return maxi;
    }
};