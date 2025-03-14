#include <bits/stdc++.h> 

int solve(vector<int> &weight, vector<int> &value, int n, int capacity,vector<vector<int>> &memo){
	if(n==0){
		if(weight[0]<=capacity) return value[0];
		else return 0;
	}
	if(memo[n][capacity]!=-1) return memo[n][capacity];

	int include=0,exclude=0;
	if(weight[n]<=capacity) include=value[n] + solve(weight,value,n-1,capacity-weight[n],memo);
	exclude=solve(weight,value,n-1,capacity,memo);
	memo[n][capacity] = max(include,exclude);
	return memo[n][capacity];
}

//this solution was taught in lovebabbar course and submitted on codingninjas
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight) //recursive+memoization solution(top-down)
{
	vector<vector<int>> memo(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,memo);
}