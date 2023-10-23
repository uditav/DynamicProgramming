//Recursion
int f(int n, int m, vector<vector<int>>& grid){
    if(m==0 && n==0){
        return grid[n][m];
    }
    if(m<0 || n<0) return 1e9;
    int up=grid[n][m]+f(n-1,m,grid);
    int left=grid[n][m]+f(n,m-1,grid);
    return min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    return f(n-1,m-1,grid);
}
TC -> O(2^N)
SC -> O(N*M)

//Memoization
int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(m==0 && n==0){
        return grid[n][m];
    }
    if(m<0 || n<0) return 1e9;
    if(dp[n][m]!=-1) return dp[n][m];
    int up=grid[n][m]+f(n-1,m,grid,dp);
    int left=grid[n][m]+f(n,m-1,grid,dp);
    return dp[n][m]=min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}
TC -> O(N*M)
SC -> O(N*M) + O(PATH LENGTH)

//Tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                dp[i][j]=grid[i][j];
            }
            else{
                int up=1e9;
                if(i>0) up=grid[i][j]+dp[i-1][j];

                int left=1e9;
                if(j>0) left=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
TC -> O(N*M)
SC -> O(N*M)

//Tabulation with space optimization
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int>prev (m,0);
    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                temp[j]=grid[i][j];
            }
            else{
                int up=1e9;
                if(i>0) up=grid[i][j]+prev[j];

                int left=1e9;
                if(j>0) left=grid[i][j]+temp[j-1];
                temp[j]=min(up,left);
            }
        }
        prev=temp;
    }
    return prev[m-1];
}
TC -> O(N*M)
SC -> O(M) + O(M)


