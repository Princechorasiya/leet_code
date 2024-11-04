//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   vector<vector<int>> findTriplets(vector<int> &arr) {
        unordered_map<int, int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        set<vector<int>>temp;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int ans=arr[i]+arr[j];
                ans=-1*ans;
                if(mp.find(ans)!=mp.end() && mp[ans]!=i && mp[ans]!=j){
                    vector<int>tempo;
                    tempo.push_back(i);
                    tempo.push_back(j);
                    tempo.push_back(mp[ans]);
                    sort(tempo.begin() ,tempo.end());
                    temp.insert(tempo);
                }
            }
        }
        vector<vector<int>>temp2(temp.begin() ,temp.end());
        return temp2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends