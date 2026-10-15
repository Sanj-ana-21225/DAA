#include<iostream>
using namespace std;
#include<queue>
struct Node{
	int val;
	Node*left;
	Node*right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
Node*BinaryTree(){
	int rootval;
	cout<<"Enter root value:";
	cin>>rootval;
	if(rootval==-1){
		return NULL;
	}
	Node*root=new Node(rootval);
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node*curr=q.front();
		q.pop();
		int leftval,rightval;
		cout<<"Enter left child of:"<<curr->val<<" ";
		cin>>leftval;
		if(leftval!=-1){
			curr->left=new Node(leftval);
			q.push(curr->left);
		}
		cout<<"Enter right child of"<<curr->val<< " ";
		cin>>rightval;
		if(rightval!=-1){
			curr->right=new Node(rightval);
			q.push(curr->right);
		}
		
	}
	return root;
}
Node*findNode(Node*root,int val){
	if(!root){
		return NULL;
	}
	if(root->val==val) 
		return root;
	Node*left=findNode(root->left,val);
	if(left) return left;
	return findNode(root->right,val);
}
Node*LCA(Node*root,Node *p,Node*q){
	if(!root|| root==p || root==q){
		return root;
	}
	Node*left =LCA(root->left,p,q);
	Node*right=LCA(root->right,p,q);
	if(left&&right){
		return root;
	}
	return left?left:right;
}
int main(){
	Node*root=BinaryTree();
	int p,q;
	cout<<"Enter p and q value:";
	cin>>p>>q;
	Node*pv=findNode(root,p);
	Node*qv=findNode(root,q);
	if(!p||!q){
		cout<<"Nodes not found in tree:";
		return 0;
	}
	Node*ancestor=LCA(root,pv,qv);
	cout<<"LCA of"<<p<<"and"<<q<<"is:"<<ancestor->val<<endl;
	return 0;
}
