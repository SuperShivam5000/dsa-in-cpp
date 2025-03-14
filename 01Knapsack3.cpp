#include <bits/stdc++.h> 

int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity) //space optimized using 2 vectors but can be optimized further
{
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);
	//base case
	for(int i=0;i<=capacity;i++){
		if(weight[0]<=i) prev[i]=value[0];
		else prev[i]=0;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=capacity;j++){
			int include = 0, exclude = 0;
            if (weight[i] <= j) include = value[i] + prev[j - weight[i]];
            exclude = prev[j];
            curr[j] = max(include, exclude);
		}
		prev=curr;
	}
	return prev[capacity];

}