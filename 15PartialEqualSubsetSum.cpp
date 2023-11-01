// using previous question

bool subsetSum(int n, int k, vector<int>& arr){
    vector<bool> curr(k+1,0), prev(k+1,0);
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
           bool nottake=prev[j];
           bool take=false;
           if (arr[i] <= j) {
             take = prev[j - arr[i]];
           }
           curr[j] = take | nottake;
        }
        prev=curr;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
	int sum=0;
	for(int i=0;i<arr.size();i++){
		sum+=arr[i];
	}
	if(sum%2!=0) return false;

	int target=sum/2;
	return subsetSum(n-1, target, arr);
}

TC-> O(N*k) + O(N)...for summing up
SC-> O(k) 
