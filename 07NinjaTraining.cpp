//Recursion
int f(int n, int last, vector<vector<int>> &points){
    if(n==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi2=0;
    for(int i=0;i<=2;i++){
            if(i!=last){
                int p=points[n][i]+f(n-1,i,points);
                maxi2=max(maxi2,p);
            }
    }
    return maxi2;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    int last=3;
    return f(n-1,last,points);
}
TC -> O(2 ^ N) ...EXPONENTIAL
SC-> O(N)

//Memoization
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi2=0;
    for(int i=0;i<=2;i++){
            if(i!=last){
                int p=points[day][i]+f(day-1,i,points,dp);
                maxi2=max(maxi2,p);
            }
    }
    return dp[day][last]=maxi2;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    int last=3;
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(n-1,last,points,dp);
}
TC -> O(N * 4 * 3)
SC -> O(N * 4) + O(N)

//Tabulation



  
