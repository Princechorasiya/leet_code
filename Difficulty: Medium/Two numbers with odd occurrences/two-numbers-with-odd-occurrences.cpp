//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
using llt =long long int;
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        vector<llt> ans;
        //find thex xor of the array 
        llt ax =0;
        for(int i=0;i<n;i++){
            ax^=arr[i];
        }
        // cout <<ax<<endl;
        //find the position of right most set bit 
        llt num = (ax &(ax-1)) ^ax;
        int i =0;
        while((ax &(1<<i))==0)i++;
       
        
        // ith bit the differentiating position f
        llt ones =0,zeros=0;
        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i))ones^=arr[j];
            else zeros^=arr[j];
        }
        return (ones < zeros) ? vector<llt>{zeros, ones} : vector<llt>{ones, zeros};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends