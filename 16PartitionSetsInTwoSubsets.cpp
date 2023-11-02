int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum=0;
	for(int i=0;i<n;i++){
		totSum+=arr[i];
	}
    int k=totSum;
	vector<vector<bool>> dp(n, vector<bool>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(arr[0]<=k){
          dp[0][arr[0]]=true;
	}

	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j){
				take=dp[i-1][j-arr[i]];
			}
			dp[i][j]=take|nottake;
		}
	}

	int mini=1e9;
	for(int i=0;i<=totSum/2;i++){
		if(dp[n-1][i]==true){
            int s1=i;
	    	int s2=totSum-s1;
		    mini=min(mini,abs(s1-s2));
		}
		
	}
	return mini;
}


