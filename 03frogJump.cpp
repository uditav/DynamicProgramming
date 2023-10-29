// Recursion ...TLE on leetcode
int f(int n, vector<int> &heights)
{
    if(n==0){
        return 0;
    }
    int left=f(n-1, heights) + abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
     right=f(n-2, heights) + abs(heights[n]-heights[n-2]);
    return min(left,right);
}

int frogJump(int n, vector<int> &heights){
    return f(n-1, heights);
}

//Memoization
int f(int n, vector<int> &heights, vector<int>& dp)
{
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    int left=f(n-1, heights,dp) + abs(heights[n]-heights[n-1]);
    int right=INT_MAX;
    if(n>1)
     right=f(n-2, heights,dp) + abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n,-1);
    return f(n-1, heights,dp);
}
TC -> O(N)
SC -> O(N) + O(N)

//Tabulation
int frogJump(int n, vector<int> &heights){
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<=n-1;i++){
       int left=dp[i-1]+abs(heights[i]-heights[i-1]);
       int right=INT_MAX;
       if(right>1){
           right=dp[i-2]+abs(heights[i]-heights[i-2]);
       }
       dp[i]=min(left,right);
   }
   return dp[n-1];
}
TC -> O(N)
SC -> O(N)

//Tabulation with space optimization
int frogJump(int n, vector<int> &heights){
    int prev2=0;
    int prev=0;
    for(int i=1;i<=n-1;i++){
       int left=prev+abs(heights[i]-heights[i-1]);
       int right=INT_MAX;
       if(right>1){
           right=prev2+abs(heights[i]-heights[i-2]);
       }
       int curr=min(left,right);
       prev2=prev;
       prev=curr;
   }
   return prev;
}
TC -> O(N)
SC -> O(1)
