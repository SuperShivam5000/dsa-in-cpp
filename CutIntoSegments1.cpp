#include<bits/stdc++.h>

int solve(int n, int x, int y, int z,vector<int> &memo){
	if(n==0) return 0;
	if(n<0) return INT_MIN;
	if(memo[n]!=-1) return memo[n];
	int r1=solve(n-x,x,y,z,memo);
	int r2=solve(n-y,x,y,z,memo);
	int r3=solve(n-z,x,y,z,memo);
	memo[n] = 1+max(r1,max(r2,r3));
	return memo[n];
}

int cutSegments(int n, int x, int y, int z) { //recursion+memoization approach(top-down)
	vector<int> memo(n+1,-1);
	int ans = solve(n,x,y,z,memo);
	if(ans<0) return 0;
	else return ans;
}