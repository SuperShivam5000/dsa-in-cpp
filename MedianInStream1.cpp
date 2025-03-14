int median(vector<int> curr, int e){
	if(e%2==0){
		int mid=e/2;
		return curr[mid];
	}
	else {
		int mid=e/2;
		return (curr[mid]+curr[mid+1])/2;
	}
}

void insertion(vector<int> &arr, int i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

vector<int> findMedian(vector<int> &arr, int n){ // time complexity O(n^2) solution (bad solution)
	vector<int> v;
	for(int i=0;i<n;i++){
		insertion(arr,i);
		v.push_back(median(arr, i));
	}
	return v;
}
