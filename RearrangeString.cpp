#include <bits/stdc++.h> 
string reArrangeString(string &s)
{
	string ans="";
	unordered_map<char,int>m;
	for(int i=0;i<s.size();i++){
		m[s[i]]++;
	}
	priority_queue<pair<int,char>> h;
	for(auto &i: m){
		pair<int,char> temp;
		temp.first=i.second;
		temp.second=i.first;
		h.push(temp);
	}
	pair<int,char> prev={0,'#'};
	while(!h.empty()){
		int topfreq=h.top().first;
		char topchar=h.top().second;
		h.pop();
		ans+=topchar;
		if(prev.first>0){
			prev.first=prev.first;
			h.push(prev);
		}
		prev={topfreq-1,topchar};
	}
	if(ans.size()==s.size()) return ans;
	else return "not possible";
}
