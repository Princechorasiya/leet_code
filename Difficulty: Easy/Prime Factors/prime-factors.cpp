//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int n) {
	    int prev = -1;
          vector<int> ans;
          int t = n;
        
          while (n % 2 == 0)
          {
            n /= 2;
            if (prev != 2)
            {
              ans.push_back(2);
              prev = 2;
            }
          }
          for (int i = 3; i <= sqrt(t); i += 2)
          {
            while (n % i == 0)
            {
              n /= i;
              if (prev != i)
              {
                ans.push_back(i);
                prev = i;
              }
            }
          }
          if (n > 1)
          {
            ans.push_back(n);
          }
          return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends