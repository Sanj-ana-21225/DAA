#include<iostream>
using namespace std;

void findLIS(int arr[],int n){
	int dp[100];
	int parent[100];
	
	for(int i=0;i<n; i++)
{
	dp[i]=1;
	parent[i]=-1;
}
for(int i=1; i<n; i++){
	for(int j=0;j<i; j++){
		if(arr[j]< arr[i]&& dp[i]<dp[j]+1){
			dp[i]=dp[j]+1;
			parent[i]=j;
		}
	}
}
int maxlength= dp[0];
int maxIndex=0;

for(int i=1;i<n; i++){
	if(dp[i]>maxlength){
		maxlength=dp[i];
		maxIndex=i;
	}
}

int lis[100];
int k=0;

while(maxIndex != -1){
	lis[100];
	int k=0;
	
	while(maxIndex!=-1){
		lis[k]=arr[maxIndex];
		k++;
		maxIndex =parent[maxIndex];
	}
	cout<<"length if lis="<<maxlength<<endl;
	cout<<"LIS =";
	for(int i=k-1;i>=0; i--){
		cout<<lis[i]<<" ";
	}
	cout<<endl;
}

}
int main()
{
	int n;
	int arr[100];
	
	cout<<"enter no. of elements\n";
	cin>>n;
	cout<<"emnter elements\n";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	findLIS(arr,n);
	return 0;
}
