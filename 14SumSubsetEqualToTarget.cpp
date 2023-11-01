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
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
TC -> O(N * k)
SC -> O(N * k) + O(N)

//Tabulation

bool f(int n, int k, vector<int>& arr, vector<vector<bool>>& dp){
    for(int i=0;i<=n;i++) dp[i][0]=true;
    if(arr[0]<=k) dp[0][arr[0]]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
           bool nottake=dp[i-1][j];
           bool take=false;
           if (arr[i] <= j) {
             take = dp[i - 1][j - arr[i]];
           }
           dp[i][j] = take | nottake;
        }
    }
    return dp[n][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    return f(n-1,k,arr,dp);
}

TC -> O(N * k)
SC -> O(N * k)

//Space optimization
bool subsetSum(int n, int k, vector<int>& arr){
    vector<bool> curr(k+1,0), prev(k+1,0);
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
           bool nottake=prev[j];
           bool take=false;
           if (arr[i] <= j) {
             take = prev[j - arr[i]];
           }
           curr[j] = take | nottake;
        }
        prev=curr;
    }
    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return subsetSum(n-1,k,arr);
}
  
TC -> O(N * k)
SC -> O(k)
