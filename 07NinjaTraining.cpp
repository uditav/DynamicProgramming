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
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4,0));
    
    dp[0][0]=max(points[0][1], points[0][2]);
    dp[0][1]=max(points[0][0], points[0][2]);
    dp[0][2]=max(points[0][0], points[0][1]);
    dp[0][3]=max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    int p=points[day][i]+dp[day-1][i];
                    dp[day][last]=max(dp[day][last],p);
                }
                
            }
        }
    }
    return dp[n-1][3];
}
TC -> O(N * 4 * 3)
SC -> O(N * 4)
    
//Tabulation with space optimization
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(n,0);
    
    prev[0]=max(points[0][1], points[0][2]);
    prev[1]=max(points[0][0], points[0][2]);
    prev[2]=max(points[0][0], points[0][1]);
    prev[3]=max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    int p=points[day][i]+prev[i];
                    temp[last]=max(temp[last],p);
                }
                
            }
        }
        prev=temp;
    }
    return prev[3];
}
TC -> O(N * 4 * 3)
SC -> O(4)

  
