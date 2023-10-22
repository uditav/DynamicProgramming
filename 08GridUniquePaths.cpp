//Recursion
int uniquePaths1(int m, int n) {
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        return uniquePaths1(m-1,n)+uniquePaths1(m,n-1);
}
int uniquePaths(int m, int n){
        return uniquePaths1(m-1,n-1);
}
TC -> O(2 ^ N*M)
SC -> O( Path Length ) ....i.e. (m-1)+(n-1)...recursion stack space

//Memoization
int uniquePaths1(int m, int n, vector<vector<int>>&dp) {
   
   if(n==0 && m==0){
	   return 1;
   }
   if(n<0 || m<0){
	   return 0;
   }
   if(dp[m][n]!=-1) return dp[m][n];
   return dp[m][n]=uniquePaths1(m-1, n,dp) + uniquePaths1(m,n-1,dp);
}

int uniquePaths(int m, int n){
   vector<vector<int>> dp(m, vector<int>(n,-1));
   return uniquePaths1(m-1, n-1,dp);
}
TC -> O(N * M)
SC -> O( Path Length ) + O(N * M)...for dp array

//Tabulation
int uniquePaths1(int m, int n, vector<vector<int>>&dp) {
	dp[0][0]=0;
   for(int i=0;i<=m;i++){
	   for(int j=0;j<=n;j++){
            if(i==0 && j==0){
				dp[0][0]=1;
			}
			else{
		        int up=0;
				int left=0;
				if(i>0) up=dp[i-1][j];
				if(j>0) left=dp[i][j-1];
				dp[i][j]=up+left;
			}
	   }
   }
   return dp[m][n];
}

int uniquePaths(int m, int n){
   vector<vector<int>> dp(m, vector<int>(n,-1));
   return uniquePaths1(m-1, n-1,dp);
}
TC -> O(N * M)
SC -> O(N * M)

//Tabulation with space optimization
int uniquePaths1(int m, int n, vector<vector<int>>&dp) {
   vector<int>prev(n+1,0);
   for(int i=0;i<=m;i++){
	   vector<int>temp(n+1,0);
	   for(int j=0;j<=n;j++){
            if(i==0 && j==0){
				temp[0]=1;
			}
			else{
		        int up=0;
				int left=0;
				if(i>0) up=prev[j];
				if(j>0) left=temp[j-1];
				temp[j]=up+left;
			}
	   }
	   prev=temp;
   }
   return prev[n];
}

int uniquePaths(int m, int n){
   vector<vector<int>> dp(m, vector<int>(n,-1));
   return uniquePaths1(m-1, n-1,dp);
}
TC -> O(N * M)
SC -> O(N) + O(N)

//Most optimal solution is not this








