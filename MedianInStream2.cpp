#include<queue>
void getMedian(int element, int &median, priority_queue<int> &maxi,
priority_queue<int,vector<int>,greater<int>> &mini){
	if(mini.size()==maxi.size()){
		//1
		if(element<median){
			maxi.push(element);
			median=maxi.top();
		} else {
			mini.push(element);
			median=mini.top();
		}
	}
	else if(mini.size()<maxi.size()){
		//2
		if(element<median){
			mini.push(maxi.top());
			maxi.pop();
			maxi.push(element);
			median=(mini.top()+maxi.top())/2;
		}
		else {
			mini.push(element);
			median=(mini.top()+maxi.top())/2;
		}
	}
	else { //mini>maxi
		//3
		if(element<median){
			maxi.push(element);
			median=(mini.top()+maxi.top())/2;
		}
		else {
			maxi.push(mini.top());
			mini.pop();
			mini.push(element);
			median=(mini.top()+maxi.top())/2;
		}
	}
}

vector<int> findMedian(vector<int> &arr, int n){ // time complexity O(nlogn) solution (good solution)
	vector<int> ans;
	int median=0;
	priority_queue<int> maxi; //remember that when ele<median then insert into maxi
	priority_queue<int,vector<int>,greater<int>> mini; //and when ele>median then insert into mini
	for(int i=0;i<n;i++){
		getMedian(arr[i],median,maxi,mini);
		ans.push_back(median);
	}
	return ans;
}
