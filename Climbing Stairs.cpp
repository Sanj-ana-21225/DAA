#include<iostream>
using namespace std;
int climbstairs(int n){
	if(n<=3) return n;
	int a=1,b=2;
	for(int i=3;i<=n;i++){
		int temp=a+b;
		a=b;
		b=temp;
	}
	return b;
}
int main(){
	int n;
	cout<<"Enter number of steps:";
	cin>>n;
	cout<<"No of distinct posibilities:"<<climbstairs(n);
	return 0;
}
