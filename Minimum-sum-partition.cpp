/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106
0 < arr[i] <= 105
*/

class Solution{
    private:
    vector<vector<bool>>subsetsum(int arr[],int n,int sum){
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }for(int j=1;j<sum+1;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp;
    }
    public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<vector<bool>>table=subsetsum(arr,n,sum);
	    vector<int>candidate;
	    for(int j=0;j<=sum/2;j++){
	        if(table[n][j]==true){
	            candidate.push_back(j);
	        }
	    }
	    int min_ans=INT_MAX;
	    for(int i=0;i<candidate.size();i++){
	        min_ans=min(min_ans,sum-2*candidate[i]);
	    }
	    return min_ans;
	}
};
