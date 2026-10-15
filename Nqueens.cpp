#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>>board;
bool isSafe(int row,int col){
	for(int i=0;i<row;i++){
		if (board[i][col]==1)
		 return false;
	}
	for(int i=row-1,j=col+1;i>=0&&j>=0;i--,j--){
		if(board[i][j]==1)
		 return false;
	}
	return true;
}
bool solve(int row){
	if(row==n)
	return true;
	for(int col=0;col<n;col++){
		if(isSafe(row,col)){
			board[row][col]=1;
			if(solve(row+1))
			 return true;
			board[row][col]=0; 
		}
    }
    return false;
}
int main(){
	cout<<"enter no.of queens:";
	cin>>n;
	board.resize(n,vector<int>(n,0));
	if(solve(0)){
		cout<<"solution:\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}else{
		cout<<"no solution exists!!";
	}
	return 0;
}

