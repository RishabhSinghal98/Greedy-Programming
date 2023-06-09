#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int,int>a,pair<int,int>b)
{
	return a.second<b.second;
}
vector<int> solve(vector<int>&start_time,vector<int>& end_time,int size)
{
	vector<pair<int,int>> activities;
	vector<int> ans;
	
	for(int i=0;i<size;i++)
	{
		pair<int,int> Pair=make_pair(start_time[i],end_time[i]);
		activities.push_back(Pair);
	 } 
	 sort(activities.begin(),activities.end(),cmp); // sorting activities in ascending order on the basis of endtime i.e second element in pair
	 
	 int count=1;  // initailizing count with 1 as we will do first activity for sure.
	 int ending_time=activities[0].second; //taking end time as first activity as end time initially
	 ans.push_back(1);
	 
	 for(int i=1;i<size;i++)
	 {
	 	if(activities[i].first>ending_time){  // if second ativities start time is greater tah end time of first activity then we will choose that activity
	 	    ans.push_back(i+1); // pushing back the index of activity choose we did +1 as string index from 1
	 		count++;
	 		ending_time=activities[i].second; // if we choose activity then end_Time will be updated with end time of that activity
	 		
		 }
	 }
	 ans.push_back(count); // at last pushing the count for storing record
	 return ans;
	 
	 
}

int main()
{
	vector<int> start_time;
	vector<int> end_time;
	int n,strt,end;

	cout<<"Enter Total Activities :";
	cin>>n;
	
	cout<<"Enter Start :";
	for(int i=0;i<n;i++)
	{
		cin>>strt;
		start_time.push_back(strt);
	}
	cout<<"Enter End Time :";
	for(int j=0;j<n;j++)
	{
		cin>>end;
		end_time.push_back(end);
	}
	vector<int> ans=solve(start_time,end_time,n);
	cout<<"No of Non-Conflicting Activities:"<<ans[ans.size()-1]<<endl; // as last element is ans is count of activities choosen
	cout<<"List Of Selected Activies:";
	for(int i=0;i<ans.size()-1;i++)
	{
	    cout<<ans[i]<<" ";
	}
}
