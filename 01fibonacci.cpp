//Fibonacci series

//Recursion
int f(int n){
        if(n<=1){
                return n;
        }
        return f(n-1)+f(n-2);
}
TC -> O(2^N)
SC -> O(N)

//Memoization
int f(int n, vector<int>& dp){
        if(n<=1){
                return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
}

int main()
{
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);
        cout<<f(n, dp);
}
TC -> O(N)
SC -> O(N) + O(N)

//Tabulation
int main()
{
        int n;
        cin>>n;
        vector<int> dp(n+1,-1);

        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
        }
        cout<<dp[n];
}
TC -> O(N)
SC -> O(N)

// Tabulation with space optimization
int main()
{
        int n;
        cin>>n;
        
        int prev2=0;
        int prev=1;
        for(int i=2;i<=n;i++){
                int curr=prev+prev2;
                prev2=prev;
                prev=curr;
        }
        cout<< prev;
}
TC -> O(N)
SC -> O(1)
