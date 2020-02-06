// https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	} 
};

int getHeight(Node* node)//O(n)
{
	if(node == NULL)
	return 0;

	int lHeight = getHeight(node->left);
	int rHeight = getHeight(node->right);

	return (max(lHeight,rHeight)+1);
}

int heightToFindDiameter(Node* node, int& diameter)
{
	if(node==NULL)
	return 0;
	
	int lHeight = heightToFindDiameter(node->left,diameter);	
	int rHeight = heightToFindDiameter(node->right,diameter);

	diameter = max(diameter,lHeight+rHeight+1);
	return (max(lHeight,rHeight)+1);	
}

int getDiameter(Node* root)
{
	int diameter = 0;
	int height = heightToFindDiameter(root,diameter);
	return diameter;
} 

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	Node *root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->left->left = new Node(7); 
	root->left->left->left->left = new Node(9); 
	root->left->right = new Node(5);
	root->left->right->right = new Node(6);
	root->left->right->right->right = new Node(8);
	cout<<getDiameter(root)<<endl; 	

}
