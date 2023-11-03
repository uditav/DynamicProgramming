//recursion
#include <bits/stdc++.h> 
int mod=(int)(1e9+7);
int subsetOfSumK(vector<int>&arr, int n, int k){
	if(n==0){
      if(arr[0]==0 && k==0) return 2;
      if(k==0 || k==arr[0]) return 1;
      return 0;
    }
	int notpick=subsetOfSumK(arr, n-1, k);
	int pick=0;
	if(arr[n]<=k) pick=subsetOfSumK(arr, n-1, k-arr[n]);
	return (pick + notpick)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }
    if((totSum-d)<0 || (totSum-d)%2!=0) return false;
    return subsetOfSumK(arr, n-1, (totSum-d)/2);
}
TC -> O(2 ^ N)
SC -> O(N)

//Tabulation
#include <bits/stdc++.h> 
 int mod=(int)(1e9+7);
int subsetOfSumK(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>>dp(n, vector<int>(k+1, 0));

    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			int notpick=dp[i-1][j];
			int pick=0;
			if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
			dp[i][j]=(pick+notpick)%mod;
		}
	}
	return dp[n-1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }
    if((totSum-d)<0 || (totSum-d)%2!=0) return false;
    return subsetOfSumK(arr, (totSum-d)/2);
}
TC -> O(N * k)
SC -> O(N * k)
  
//Tabulation with space optimization#include <bits/stdc++.h> 
 int mod=(int)(1e9+7);
int subsetOfSumK(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> prev(k+1,0), curr(k+1, 0);
/*
    if(arr[0]==0) dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]]=1;
*/

	if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			int notpick=prev[j];
			int pick=0;
			if(arr[i]<=j) pick=prev[j-arr[i]];
			curr[j]=(pick+notpick)%mod;
		}
		prev=curr;
	}
	return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }
    if((totSum-d)<0 || (totSum-d)%2!=0) return false;
    return subsetOfSumK(arr, (totSum-d)/2);
}
TC -> O(N * k)
SC -> O(N)


