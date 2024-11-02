//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        //create the graph first 
        //create the adjList 
        vector<vector<int>> adjList(v);
        for(auto i:edges){
            int u =i.first;
            int v =i.second;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // after that apply dfs at each node find the first free color 
        vector<int> visited(v,0);
        unordered_map<int,int> colors;
        bool ans =dfs(adjList,colors,m,0);
        return ans;
    }
    
    bool dfs(vector<vector<int>> & adjList,unordered_map<int,int> &colors,int m,int src){\
        if(src==adjList.size())return true;
        //chekc for each of hte color 
        for(int i=1;i<=m;i++){
            //now check if that color can be valid or not 
            
            bool canUse = true;
            for(auto j:adjList[src]){
                    // cout <<i<<" "<<colors[j]<<endl;
                    if(colors[j]==i){
                        canUse=false;
                        break;
                    }
            }
            if (canUse) {
                    // cout <<i<<endl;
                    colors[src] = i;
                    if (dfs(adjList, colors, m, src + 1)) return true;
                    colors[src] = 0;
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends