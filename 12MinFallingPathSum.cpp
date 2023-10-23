//Recursion
int f(vector<vector<int>> &matrix, int i, int j, int m){
    if(j<0 || j>m-1){
        return -1e9;
    }
    if(i==0){
        return matrix[i][j];
    }
    int a=matrix[i][j]+f(matrix,i-1,j-1,m);
    int b=matrix[i][j]+f(matrix,i-1,j,m);
    int c=matrix[i][j]+f(matrix,i-1,j+1,m);
    return max(a,max(b,c));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    for(int j=0;j<m;j++){
          maxi=max(maxi,f(matrix,n-1,j,m));
    }
    return maxi;
}
TC -> O(3^N) exponential
SC -> O(N)

//Memoization
int f(vector<vector<int>> &matrix, int i, int j, int m, vector<vector<int>> &dp){
    if(j<0 || j>m-1){
        return -1e9;
    }
    if(i==0){
        return matrix[i][j];
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int a=matrix[i][j]+f(matrix,i-1,j-1,m,dp);
    int b=matrix[i][j]+f(matrix,i-1,j,m,dp);
    int c=matrix[i][j]+f(matrix,i-1,j+1,m,dp);
    return dp[i][j]=max(a,max(b,c));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int maxi=-1e9;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    for(int j=0;j<m;j++){
          maxi=max(maxi,f(matrix,n-1,j,m,dp));
    }
    return maxi;
}
TC -> O(N*M) 
SC -> O(N) + O(N*M)

//Tabulation

TC -> O(N*M) + O(M)
SC -> O(N*M)

//Tabulation with space optimization
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for (int j = 0; j < m; j++) {
            int a = matrix[i][j];
            int b = matrix[i][j] + dp[i-1][j];
            int c = matrix[i][j];
            if(j-1>=0){
              a += dp[i-1][j-1];
            }
            else{
                a+=-1e9;
            }
            if(j+1<m){
              c += dp[i-1][j+1];
            }
            else{
                c+=-1e9;
            }
          
          dp[i][j] = max(a, max(b, c));
        }
    }

    int maxi=-1e9;
    for(int j=0;j<m;j++){
          maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
}
TC -> O(N*M) + O(M)
SC -> O(M)
  
  
