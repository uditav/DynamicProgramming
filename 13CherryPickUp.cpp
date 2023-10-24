//Recursion
int f(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n){
     if(j1<0 || j1>=m || j2<0 || j2>=m){
         return -1e9;
     }
     if(i==n-1){
         if(j1==j2) return grid[i][j1];
         else return grid[i][j1]+grid[i][j2];
     }
     int maxi=0;
     for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            if(j1==j2){
               maxi = max(maxi, grid[i][j1] + f(i+1,j1+d1,j2+d2,grid,m,n));
            }
            else{
               maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1,j1+d1,j2+d2,grid,m,n));
            }
        }   
     }
     return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return f(0,0,c-1,grid,grid[0].size(),grid.size());
}
TC -> O(3^N * 3^N)...exponential
SC -> O(N)...auxiliary stack space

//Memoization
int f(int i, int j1, int j2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
     if(j1<0 || j1>=m || j2<0 || j2>=m){
         return -1e9;
     }
     if(i==n-1){
         if(j1==j2) return grid[i][j1];
         else return grid[i][j1]+grid[i][j2];
     }
     if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
     int maxi=0;
     for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            if(j1==j2){
               maxi = max(maxi, grid[i][j1] + f(i+1,j1+d1,j2+d2,grid,m,n,dp));
            }
            else{
               maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i+1,j1+d1,j2+d2,grid,m,n,dp));
            }
        }   
     }
     return dp[i][j1][j2]=maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    return f(0,0,c-1,grid,grid[0].size(),grid.size(),dp);
}
TC -> O(N*M*M) * 9  .....for all 9 states
SC -> O(N*M*M) + O(N)

//Tabulation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,0)));
    
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
            else dp[n-1][j1][j2]=grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e9;
                for(int d1=-1;d1<=1;d1++){
                    for(int d2=-1;d2<=1;d2++){
                        int value=0;
                        if(j1==j2)  value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        if(j1+d1>=0 && j1+d1<m && j2+d2>=0 &&  j2+d2<m){
                            value+=dp[i+1][j1+d1][j2+d2];
                        }
                        else{
                            value+=-1e9;
                        }
                        maxi=max(maxi,value);
                    }   
                }
                dp[i][j1][j2]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
TC -> O(N*M*M) 
SC -> O(N*M*M) 
     
//Tabulation with space optimization
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) front[j1][j2]=grid[n-1][j1];
            else front[j1][j2]=grid[n-1][j1] + grid[n-1][j2];
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                int maxi=-1e9;
                for(int d1=-1;d1<=1;d1++){
                    for(int d2=-1;d2<=1;d2++){
                        int value=0;
                        if(j1==j2)  value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        if(j1+d1>=0 && j1+d1<m && j2+d2>=0 &&  j2+d2<m){
                            value+=front[j1+d1][j2+d2];
                        }
                        else{
                            value+=-1e9;
                        }
                        maxi=max(maxi,value);
                    }   
                }
                curr[j1][j2]=maxi;
            }
        }
        front=curr;
    }
    return front[0][m-1];
}
TC -> O(N*M*M) 
SC -> O(M*M)


