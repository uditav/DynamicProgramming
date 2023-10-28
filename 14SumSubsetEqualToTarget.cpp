//DP on Subsequences
A subsequence must be contiguous or non-contiguous, but it should be  in order

//Recursion
bool subsetSumToK(int n, int k, vector<int> &arr) {
    if(k==0) return true;
    if(n==0) return arr[n]==k;
    
    bool nottake=subsetSumToK(n-1,k,arr);
    bool take=false;
    if(arr[n]<=k){
        take=subsetSumToK(n-1,k-arr[n],arr);
    }
    return take || nottake;
}
TC -> O(2^N)
SC -> O(N)

//Memoization
bool f(int n, int k, vector<int> &arr, vector<vector<int>>& dp) {
    if(k==0) return true;
    if(n==0) return arr[n]==k;
    if(dp[n][k]!=-1) return dp[n][k];
    bool nottake=f(n-1,k,arr,dp);
    bool take=false;
    if(arr[n]<=k){
        take=f(n-1,k-arr[n],arr,dp);
    }
    return dp[n][k]=take || nottake;
}

bool subsetSumToK(int n, int k, vector<int> &arr){
    vector<vector<int>> dp(10000,vector<int>(1000,-1));
    return f(n-1,k,arr,dp);
}
TC -> O(N * k)
SC -> O(N * k) + O(N)





  
