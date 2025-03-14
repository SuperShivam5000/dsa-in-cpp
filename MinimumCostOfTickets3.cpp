int minimumCoins(int n, vector<int> days, vector<int> cost) //space optimized solution using queue
{
    int ans=0;

    queue<pair<int,int>> week; //day,cost
    queue<pair<int,int>> month; //day,cost

    for(auto &day: days){
        //remove expired days
        while(!week.empty() && week.front().first+7<=day) week.pop();
        while(!month.empty() && month.front().first+30<=day) month.pop();

        //add cost for current days
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        //update answer
        ans=min(ans+cost[0],min(week.front().second,month.front().second));
    }
    
    return ans;
}