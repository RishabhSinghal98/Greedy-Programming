#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct items{
	int weight;
	int profit;
};
static bool cmp(pair<double,items> a,pair<double,items> b)
{
	return a.first>b.first;
}

double find_profit(items Items[],int size,int capacity)
{
	vector<pair<double,items>> fractional;   // created a vector fractional having pair data one int type and another of items type
	
	for(int i=0;i<size;i++)
	{
		double per_unit_val=(1.0*Items[i].profit)/Items[i].weight; // computed per_unit_value
		
		pair<double,items> Pair=make_pair(per_unit_val,Items[i]); // made a pair  of integer type and struct items type
		fractional.push_back(Pair);                               // pushed the pair in fractional(vector)
	}
	
	sort(fractional.begin(),fractional.end(),cmp);  // sorted the fractional on the basis of per_unit _val
	
	
	// traversing through fractional vector
	
	double total_profit=0;
	for(int i=0;i<size;i++)
	{
		if(fractional[i].second.weight>capacity) // if weight of fractional vector is greater than that of capacity so take (per_unit_val *capacity) and set capacity==0
		{
			total_profit+=fractional[i].first*capacity; 
			capacity=0;
		}
		else {
			total_profit+=fractional[i].second.profit; // else take profit and add with total_profit and reduce the capacity by weight of that item
			capacity-=fractional[i].second.weight;
		}
	}
	return total_profit;
}


int main()
{ 
    int n;
    int capacity;
    cout<<"Enter the Capacity"<<endl;
    cin>>capacity;
    cout<<"Enter number of weights/items"<<endl;
    cin>>n;
    struct items Items[n]; // created an array of struct items 
	 
	cout<<"Enter profit:Weight"<<endl;
	for (int i = 0; i < n; i++) {  //taking input in array
        cin >> Items[i].profit;
        cin >> Items[i].weight; 
    }
	
	double ans =find_profit(Items,n,capacity);
	cout<<"The  maximum Profit is "<< ans;
	
	return 0;
}
