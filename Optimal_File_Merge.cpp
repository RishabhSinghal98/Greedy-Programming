#include<bits/stdc++.h>
using namespace std;

int mincost(vector<int> &files,int size)
{
	priority_queue<int,vector<int>,greater<int>> pq; // created min heap
	int total_min_cost=0;
	
	for(int i=0;i<size;i++)
	{
		pq.push(files[i]);   // pushing elements from files into min heap pq
	}
	int temp_cost=0;
	int count=0;
	
	while(pq.size()>1)
	{
	    int temp_cost=0;
		temp_cost+=pq.top();
		pq.pop();
		temp_cost+=pq.top();
		pq.pop();
		total_min_cost+=temp_cost;
		pq.push(temp_cost);
	}
	return total_min_cost;
}

int main()
{
	int size;
	cout<<"Enter Size of array"<<endl;
	cin>>size;
	int n;
	vector<int> files;
	cout<<"Enter sizes  of files"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>n;
		files.push_back(n);
	}

    int cost=mincost(files,size);
    
    cout<<"Minimumum Computations Are "<<cost;
	
	return 0;
	
	
	
	
}
