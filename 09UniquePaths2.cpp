//Recursion
int mod=(int)(1e9+7);
int mazeObstacles1(int n, int m, vector< vector< int> > &mat) {
    if(n>=0 && m>=0 && mat[n][m]==-1) return 0;
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;

    return (mazeObstacles1(n-1,m,mat) + mazeObstacles1(n,m-1,mat))%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat){
    return mazeObstacles1(n-1, m-1, mat);
}

//Memoization
int mod=(int)(1e9+7);
int mazeObstacles1(int n, int m, vector< vector< int> > &mat, vector< vector< int> > &dp) {
    if(n>=0 && m>=0 && mat[n][m]==-1) return 0;
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]=(mazeObstacles1(n-1,m,mat,dp) + mazeObstacles1(n,m-1,mat,dp))%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat){
    vector<vector<int>> dp(n, vector<int>(m,-1));
    return mazeObstacles1(n-1, m-1, mat,dp);
}
//Tabulation
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat){
    vector<vector<int>> dp(n, vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i>=0 && j>=0 && mat[i][j]==-1) dp[i][j]=0;
            else if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}

//Tabulation with space optimization
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat){
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> temp(m,0);
        for(int j=0;j<m;j++){
            if(i>=0 && j>=0 && mat[i][j]==-1) temp[j]=0;
            else if(i==0 && j==0){
                temp[j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=temp[j-1];
                temp[j]=(up+left)%mod;
            }
        }
        prev=temp;
    }
    return prev[m-1];
}
