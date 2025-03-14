#include <queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> h;
	for(int i=0;i<arr.size();i++){
		int sum=0;
		for(int j=i;j<arr.size();j++){
			sum+=arr[j];
			if(h.size()<k) h.push(sum);
			else if(h.top()<sum) {h.pop(); h.push(sum);}
		}
	}
	return h.top();
}