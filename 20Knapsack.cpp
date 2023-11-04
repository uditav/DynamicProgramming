//RECURSION
int f(vector<int> weight, vector<int> value, int n, int maxWeight){
	if(n==0){
       if(maxWeight>=weight[0]) return value[0];
   	   else return 0;
	}
	int notpick=f(weight,value,n-1,maxWeight);
	int pick=INT_MIN;
	if(weight[n]<=maxWeight) pick=value[n]+f(weight,value,n-1,maxWeight-weight[n]);
	return max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return f(weight,value,n-1,maxWeight);
}
TC -> O(2 ^ N)
SC -> O(N)

//MEMOIZATION
int f(vector<int> weight, vector<int> value, int n, int maxWeight, vector<vector<int>>& dp){
	if(n==0){
       if(maxWeight>=weight[0]) return value[0];
   	   else return 0;
	}
	if(dp[n][maxWeight]!=-1) return dp[n][maxWeight];
	int notpick=f(weight,value,n-1,maxWeight, dp);
	int pick=INT_MIN;
	if(weight[n]<=maxWeight) pick=value[n]+f(weight,value,n-1,maxWeight-weight[n], dp);
	return dp[n][maxWeight]=max(pick,notpick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1,-1));
	return f(weight,value,n-1,maxWeight,dp);
}
TC -> O(maxWeight * N)
SC -> O(maxWeight * N) + O(N)

//TABULATION
  int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1,0));
    for (int i = weight[0]; i <= maxWeight; i++) {
			dp[0][i]=value[0];
    }

	for(int i=1;i<n;i++){
		for(int j=0;j<=maxWeight;j++){
			int notpick=dp[i-1][j];
	        int pick=INT_MIN;
         	if(weight[i]<=j) pick=value[i]+dp[i-1][j-weight[i]];
	        dp[i][j]=max(pick,notpick);
		}
	}

	return dp[n-1][maxWeight];
}
TC -> O(maxWeight * N)
SC -> O(maxWeight * N)
  
//TABULATION with space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0), curr(maxWeight+1,0);
    for (int i = weight[0]; i <= maxWeight; i++) {
			prev[i]=value[0];
    }

	for(int i=1;i<n;i++){
		for(int j=0;j<=maxWeight;j++){
			int notpick=prev[j];
	        int pick=INT_MIN;
         	if(weight[i]<=j) pick=value[i]+prev[j-weight[i]];
	        curr[j]=max(pick,notpick);
		}
		prev=curr;
	}

	return prev[maxWeight];
}
TC -> O(maxWeight * N)
SC -> O(maxWeight+1) + O(maxWeight+1)

//TABULATION with more space optimization
  int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1,0);
    for (int i = weight[0]; i <= maxWeight; i++) {
			prev[i]=value[0];
    }

	for(int i=1;i<n;i++){
		for(int j=maxWeight;j>=0;j--){
			int notpick=prev[j];
	        int pick=INT_MIN;
         	if(weight[i]<=j) pick=value[i]+prev[j-weight[i]];
	        prev[j]=max(pick,notpick);
		}
	}

	return prev[maxWeight];
}
TC -> O(maxWeight * N)
SC -> O(maxWeight+1)
