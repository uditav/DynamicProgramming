//Recursion
int minimumPathSum1(vector<vector<int>>& triangle, int n, int i, int j){
   if(i==n-1){
        return triangle[n-1][j];
   }
   int down=triangle[i][j]+minimumPathSum1(triangle, n, i+1, j);
   int digonal=triangle[i][j]+minimumPathSum1(triangle, n, i+1, j+1);
   return min(down,digonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	return minimumPathSum1(triangle,n,0,0);
}
TC -> O(2 ^ N)...EXPONENTIAL
SC -> O(N)

//Memoization
int minimumPathSum1(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>>& dp){
   if(i==n-1){
        return triangle[n-1][j];
   }
   if(dp[i][j]!=-1) return dp[i][j];
   int down=triangle[i][j]+minimumPathSum1(triangle, n, i+1, j,dp);
   int digonal=triangle[i][j]+minimumPathSum1(triangle, n, i+1, j+1, dp);
   return dp[i][j]=min(down,digonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n,-1));
	return minimumPathSum1(triangle,n,0,0,dp);
}
TC -> O(N * N)
SC -> O(N) + O(N * N)

//Tabulation
Note: Whatever you write for recursion, tabulation will be its opposite...(Thumb Rule)
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n,0));
	for(int j=0;j<n;j++){
		dp[n-1][j]=triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
				int down=triangle[i][j]+dp[i+1][j];
				int digonal=triangle[i][j]+dp[i+1][j+1];
				dp[i][j]=min(down,digonal);
		}
	}
	return dp[0][0];
}
TC -> O(N * N)
SC -> O(N * N)

//Tabulation with space optimization
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int> front(n,0);
	for(int j=0;j<n;j++){
		front[j]=triangle[n-1][j];
	}
	for(int i=n-2;i>=0;i--){
		vector<int> curr(n,0);
        for(int j=i;j>=0;j--){
				int down=triangle[i][j]+front[j];
				int digonal=triangle[i][j]+front[j+1];
				curr[j]=min(down,digonal);
		}
		front=curr;
	}
	return front[0];
}
TC -> O(N * N)
SC -> O(N)
