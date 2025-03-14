class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int min_cost=0;
        int i=0,j=N-1;
        while(i<=j){
            min_cost+=candies[i];
            j=j-K;
            i++;
        }
        int max_cost=0;
        i=N-1;j=0;
        while(i>=j){
            max_cost+=candies[i];
            j=j+K;
            i--;
        }
        vector<int> ans;
        ans.push_back(min_cost);
        ans.push_back(max_cost);
        return ans;
    }
};