//Recursion
int find(vector<int>&arr, int n, int k){
	if(k==0) return 1;
	if(n==0) return k==arr[0];
	int notpick=find(arr, n-1, k);
	int pick=0;
	if(arr[n]<=k) pick=find(arr, n-1, k-arr[n]);
	return pick + notpick;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size()-1;
	 return find(arr,n,k);
}
TC -> O(2 ^ N)
SC -> O(N)

//Memoization
int mod=1e9+7;
int find(vector<int>& arr, int n, int k, vector<vector<int>>& dp){
	if(k==0) return 1;
	if(n==0) return k==arr[0];
	if(dp[n][k]!=-1) return dp[n][k];
	int notpick=find(arr, n-1, k, dp);
	int pick=0;
	if(arr[n]<=k) pick=find(arr, n-1, k-arr[n], dp);
	return dp[n][k]=(pick + notpick)%mod;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return find(arr,n-1,k, dp);
}

TC -> O(N * k)
SC -> O(N * k) + O(N)

//Tabulation
int mod=1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, 0));

	for(int i=0;i<n;i++) dp[i][0]=1;
	if(arr[0]<=k) dp[0][arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			int notpick=dp[i-1][j];
			int pick=0;
			if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
			dp[i][j]=(pick+notpick)%mod;
		}
	}
	return dp[n-1][k];
}
TC -> O(N * k)
SC -> O(N * k)

  //Space optimization
  int mod=1e9+7;
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> prev(k+1,0), curr(k+1);

	prev[0]=curr[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			int notpick=prev[j];
			int pick=0;
			if(arr[i]<=j) pick=prev[j-arr[i]];
			curr[j]=(pick+notpick)%mod;
		}
		prev=curr;
	}
	return prev[k];
}
TC -> O(N * k)
SC -> O(N)

//1st way of considering zeroes
return pow(2,n) * ans; where n is the number of zeroes in the array

//2nd way bt changing the base case
int find(vector<int>&arr, int n, int k){
	if(n==0){
    if(arr[0]==0 && k==0) return 2;
    if(k==0 || k==arr[0]) return 1;
    return 0;
  }
	int notpick=find(arr, n-1, k);
	int pick=0;
	if(arr[n]<=k) pick=find(arr, n-1, k-arr[n]);
	return pick + notpick;
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size()-1;
	 return find(arr,n,k);
}

	
