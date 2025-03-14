#include <bits/stdc++.h> 

int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity) //tabulation approach(bottom-up)
{
	vector<vector<int>> memo(n,vector<int>(capacity+1,0));

	//base case
	for(int i=0;i<=capacity;i++){
		if(weight[0]<=i) memo[0][i]=value[0];
		else memo[0][i]=0;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=capacity;j++){
			int include = 0, exclude = 0;
            if (weight[i] <= j) include = value[i] + memo[i - 1][j - weight[i]];
            exclude = memo[i - 1][j];
            memo[i][j] = max(include, exclude);
		}
	}
	return memo[n-1][capacity];

}