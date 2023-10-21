//same as previous question
//apply same logic on indices 0 to n-1 and on indices 1 to n

long long int m(vector<int>& nums, int n){
    long long int prev2=0;
    long long int prev=nums[0];
    for(int i=1;i<=n;i++){
       long long int pick=nums[i]; if(i>1) pick+=prev2;
       long long int notpick=0+prev;
       long long int curr=max(pick,notpick);
       prev2=prev;
       prev=curr;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    vector<int> temp1;
    vector<int> temp2;
    for(int i=0;i<n;i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(m(temp1,temp1.size()-1), m(temp2, temp2.size()-1));
}
T->O(n)
S->O(1)


