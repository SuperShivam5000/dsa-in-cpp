//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    int maxdead(Job arr[], int n) {
        int max=arr[0].dead;
        for(int i=0;i<n;i++){
            if(arr[i].dead>max) max=arr[i].dead;
        }
        return max;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int jobs=0,profit=0;
        sort(arr,arr+n,cmp);
        int maxdeadline=maxdead(arr,n);
        vector<int> schedule(maxdeadline + 1, -1);
        for(int i=0;i<n;i++){
            int j=arr[i].dead;
            while(j>0){
                if(schedule[j]==-1){
                    schedule[j]=1;
                    jobs++;
                    profit+=arr[i].profit;
                    break;
                }
                j--;
            }
        }
        vector<int> ans;
        ans.push_back(jobs);
        ans.push_back(profit);
        return ans;
        
        // vector<int> x;
        // x.push_back(2);
        // return x;
    }
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends