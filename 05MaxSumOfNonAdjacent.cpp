//Recursion
int maximumNonAdjacentSum1(vector<int> nums, int n){
    if(n==0) return nums[0];
    if(n<0)  return 0;
    int pick=nums[n]+maximumNonAdjacentSum1(nums, n-2);
    int notpick=0+maximumNonAdjacentSum1(nums, n-1);
    return max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size()-1;
    return maximumNonAdjacentSum1(nums,n);
}
TC -> O(2^N)
SC -> O(N)

//Memoization
int maximumNonAdjacentSum1(vector<int> nums, int n, vector<int>& dp){
    if(n==0) return nums[0];
    if(n<0)  return 0;
    if(dp[n]!=-1) return dp[n];
    int pick=nums[n]+maximumNonAdjacentSum1(nums, n-2, dp);
    int notpick=0+maximumNonAdjacentSum1(nums, n-1, dp);
    return dp[n]=max(pick,notpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return maximumNonAdjacentSum1(nums,n-1,dp);
}
TC -> O(N)
SC -> O(N) + O(N)
  
 //Tabulation
int maximumNonAdjacentSum1(vector<int> nums, int n, vector<int>& dp){
    dp[0]=nums[0];
    int neg=0;
    for(int i=1;i<=n;i++){
        int pick = nums[i]; if(i>1) pick+=dp[i-2];
        int notpick = 0 + dp[i-1];
        dp[i] = max(pick,notpick);
    }
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,-1);
    return maximumNonAdjacentSum1(nums,n-1,dp);
}
TC -> O(N)
SC -> O(N)

//Tabulation with space optimization
int maximumNonAdjacentSum1(vector<int> nums, int n){
    int prev=nums[0];
    int prev2=0;
    int curr=nums[0];
    for(int i=1;i<=n;i++){
        int pick = nums[i]; if(i>1) pick+=prev2;
        int notpick = 0 + prev;
        curr = max(pick,notpick);
        prev2=prev;
        prev=curr;
    }
    return curr;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return maximumNonAdjacentSum1(nums,n-1);
}
TC -> O(N)
SC -> O(1)
  
