//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
      int l = 0, maxi = 0;
        int n = arr.size();
        unordered_map<int, int> mp;
    
        for (int r = 0; r < n; r++) {
            if (mp.count(arr[r]) == 0 && mp.size() == 2) {
                int mink = -1, minV = INT_MAX;
                for (auto it = mp.begin(); it != mp.end(); ++it) {
                    if (it->second < minV) {
                        minV = it->second;
                        mink = it->first;
                    }
                }
                mp.erase(mink);
                l = minV + 1;
            }
    
            mp[arr[r]] = r;
            maxi = max(maxi, r - l + 1);
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends