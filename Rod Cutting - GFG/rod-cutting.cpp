//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int memo(int i,int price[],int n,vector<vector<int>> &dp){
        if(i==0){
            return (n/(i+1))*price[i];
        }
        if(dp[i][n]!=-1)
            return dp[i][n];
        int notTake = 0 + memo(i-1,price,n,dp);
        int rodlen = i+1;
        int take = (rodlen<=n) ? price[i] + memo(i,price,n-rodlen,dp) : INT_MIN; 
        return dp[i][n]=max(take,notTake);
    }
    int recur(int i , int price[], int n){
        
        if(i==0){
            return (n/(i+1))*price[i];
        }
        
        int notTake = 0 + recur(i-1,price,n);
        int rodlen = i+1;
        int take = (rodlen<=n) ? price[i] + recur(i,price,n-rodlen) : INT_MIN; 
        return max(take,notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        // return recur(n-1,price,n);
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return memo(n-1,price,n,dp);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends