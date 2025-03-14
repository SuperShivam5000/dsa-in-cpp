#include <bits/stdc++.h> 

int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity) //most space optimized solution using single vector only
{
	vector<int> curr(capacity+1,0);
	//base case
	for(int i=0;i<=capacity;i++){
		if(weight[0]<=i) curr[i]=value[0];
		else curr[i]=0;
	}

	for(int i=1;i<n;i++){
		for(int j=capacity;j>=0;j--){ //iterate right to left to prevent overwrite
			int include = 0, exclude = 0;
            if (weight[i] <= j) include = value[i] + curr[j - weight[i]];
            exclude = curr[j];
            curr[j] = max(include, exclude);
		}
	}
	return curr[capacity];
}