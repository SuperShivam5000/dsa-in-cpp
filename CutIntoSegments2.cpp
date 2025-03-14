#include <bits/stdc++.h>
int cutSegments(int n, int x, int y, int z) { //tabulation approach(bottom-up)
	vector<int> memo(n+1,-1);
	memo[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0&&memo[i-x]!=-1) memo[i]=max(memo[i],1+memo[i-x]);
		if(i-y>=0&&memo[i-y]!=-1) memo[i]=max(memo[i],1+memo[i-y]);
		if(i-z>=0&&memo[i-z]!=-1) memo[i]=max(memo[i],1+memo[i-z]);
	}
	if(memo[n]<0) return 0;
	else return memo[n];
}