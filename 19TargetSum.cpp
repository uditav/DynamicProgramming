#include <bits/stdc++.h> 
int subsetOfSumK(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<int> prev(k+1,0), curr(k+1, 0);

	if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++){
			int notpick=prev[j];
			int pick=0;
			if(arr[i]<=j) pick=prev[j-arr[i]];
			curr[j]=(pick+notpick);
		}
		prev=curr;
	}
	return prev[k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(int i=0;i<n;i++){
        totSum+=arr[i];
    }
    if((totSum-d)<0 || (totSum-d)%2!=0) return false;
    return subsetOfSumK(arr, (totSum-d)/2);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
