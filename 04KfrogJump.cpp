//Recursion
int minimizeCost1(int n, int k, vector<int> &height){
    // Write your code here.
    if(n==0){
        return 0;
    }
    int minstep=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int step=minimizeCost1(n-i, k, height) + abs(height[n]-height[n-i]);
            minstep=min(step,minstep);
        }
        
    }
    return minstep;
}

int minimizeCost(int n, int k, vector<int> &height){
    return minimizeCost1(n-1, k, height);
}
TC -> O(2 ^ N)
SC -> O(N)
  
//Memoization
int minimizeCost1(int n, int k, vector<int> &height, vector<int>& dp){
    // Write your code here.
    if(n==0){
        return 0;
    }
    int minstep=INT_MAX;
    if(dp[n]!=-1) return dp[n];
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int step= minimizeCost1(n-i, k, height, dp) + abs(height[n]-height[n-i]);
            minstep=min(step,minstep);
        }
        dp[n]=minstep;
    }
    return dp[n];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    return minimizeCost1(n-1, k, height,dp);
}
TC -> O(N * k)
SC -> O(N) + O(N)

//Tabulation
  int minimizeCost1(int n, int k, vector<int> &height, vector<int>& dp){
    // Write your code here.
    dp[0]=0;
    for(int j=1;j<=n;j++){
        int minstep=INT_MAX;
        for(int i=1;i<=k;i++){
          if(j-i>=0){
            int step= dp[j-i] + abs(height[j]-height[j-i]);
            minstep=min(step,minstep);
          }
          dp[j]=minstep;
        }
    }
    return dp[n];
}

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,-1);
    return minimizeCost1(n-1, k, height,dp);
}
TC -> O(N * k)
SC -> O(N)

///Tabulation with space optimization
It is possible only upto O(k) if we will store the last k values in an array, otherwise, in the worst case, it will go upto O(N).

  
