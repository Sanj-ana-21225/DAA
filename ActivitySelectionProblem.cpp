#include<iostream>
#include<algorithm>
using namespace std;

struct Activity{
	int start;
	int finish;
};

bool compare(Activity a, Activity b){
	return a.finish<b.finish;
}

void activityselection(Activity activities[],int n){
	
	sort(activities,activities+n,compare);
	cout<<"selected activities:";
	
	int lastFinish=activities[0].finish;
	
	
	cout<<"("<<activities[0].start<< ","  <<activities[0].finish<<")";
	
	for(int i=1;i<n;i++){
		if(activities[i].start>=lastFinish){
			cout<< "(" << activities[i].start<< "," <<activities[i].finish<<")";
			lastFinish=activities[i].finish;
		}
	}
}

int main(){
	int n;
	cout<<"enter number of activities\n"; 
	cin>>n;
	Activity activities[n];
	cout<<"enter start times\n";
	for(int i=0;i<n;i++){
		cin>>activities[i].start;
		}
		cout<<"enter finish times\n";
		for(int i=0;i<n;i++){
		cin>>activities[i].finish;
	}
	
	activityselection(activities,n);
	
	return 0;

	}
	
